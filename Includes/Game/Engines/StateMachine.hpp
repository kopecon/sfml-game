//
// Created by Andrew on 08/12/2025.
//

#ifndef BONK_GAME_STATE_MACHINE_ENGINE_HPP
#define BONK_GAME_STATE_MACHINE_ENGINE_HPP
#include <cassert>
#include <functional>
#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>


template <typename Manager>
class StateBase {
protected:
    Manager *pManager{nullptr};
public:
    virtual ~StateBase() = default;
    StateBase(Manager *pManager, const typename Manager::States &stateID) :
    pManager(pManager),
    stateID(stateID)
    {}

    typename Manager::States stateID{};
    StateBase *pPreviousState{nullptr};

    virtual void onEnter() {
        // std::cout << pManager->pPlayer->name << " Entered state: " << static_cast<int>(stateID) << "\n";
    }
    virtual void onExit() {
        // std::cout << pManager->pPlayer->name << " Exited state: " << static_cast<int>(stateID) << "\n";
    }

    virtual void update() = 0;

    virtual typename Manager::States next(const std::vector<typename Manager::States> &conditions) = 0;
};

template<typename Manager>
class State final : public StateBase<Manager>{
public:
    State(Manager *pManager, const typename Manager::States &stateID)
        : StateBase<Manager>(pManager, stateID) {
    }

    std::function<void()> updateFn{};
    std::function<typename Manager::States (const std::vector<typename Manager::States> &)> nextFn{};

    void update() override {
        updateFn();
    }

    typename Manager::States next(const std::vector<typename Manager::States> &conditions) override {
        typename Manager::States nextState = nextFn(conditions);
        return nextState;
    }
};


template<typename Manager>
class StateMachine {
    Manager *pManager{};
public:
    StateMachine() = default;
    explicit StateMachine(Manager *pManager) : pManager(pManager) {}

    StateBase<Manager> *pCurrentState{nullptr};
    typename Manager::States targetStateID{};  // Usually triggered by the user's input
    std::vector<typename Manager::States> conditions{};
    // List of available states
    std::unordered_map<typename Manager::States, std::unique_ptr<StateBase<Manager>>> states{};

    template<typename T>
    void addState(std::unique_ptr<T> pState)
    requires std::is_base_of_v<StateBase<Manager>, T> {
        auto [it, inserted] = states.emplace(pState->stateID, std::move(pState));

        if (!pCurrentState && inserted) {
            pCurrentState = it->second.get();
        }
    }

    void createState(typename Manager::States stateID, std::function<void()> update, std::function<typename Manager::States(const std::vector<typename Manager::States> &)> next) {
        auto createdState = std::make_unique<State<Manager>>(pManager, stateID);
        createdState->updateFn = std::move(update);
        createdState->nextFn = std::move(next);
        addState(std::move(createdState));
    }

    void act() const {
        if (pCurrentState != nullptr) pCurrentState->update();
    }

    void transition(const typename Manager::States &stateID) {
        auto pNextState = states.at(stateID).get();
        pNextState->pPreviousState = pCurrentState;
        pCurrentState = pNextState;
        pCurrentState->onEnter();
    }

    void update() {
        assert(pCurrentState != nullptr);
        pCurrentState->update();
        conditions.clear();
        conditions.push_back(targetStateID);
        auto newState = pCurrentState->next(conditions);
        if (newState != pCurrentState->stateID) {
            pCurrentState->onExit();
            transition(newState);
        }
    }
};

#endif //BONK_GAME_STATE_MACHINE_ENGINE_HPP
