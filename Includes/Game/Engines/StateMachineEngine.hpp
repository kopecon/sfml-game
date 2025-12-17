//
// Created by Andrew on 08/12/2025.
//

#ifndef BONK_GAME_STATE_MACHINE_ENGINE_HPP
#define BONK_GAME_STATE_MACHINE_ENGINE_HPP
#include <assert.h>
#include <iostream>
#include <memory>
#include <vector>
#include <unordered_map>


template <typename Manager>
class State {
protected:
    Manager *pManager{nullptr};
public:
    virtual ~State();
    State(Manager *pManager, const typename Manager::States &stateID) :
    pManager(pManager),
    stateID(stateID)
    {}

    typename Manager::States stateID{};
    State *pPreviousState{nullptr};

    virtual void onEnter() {}
    virtual void onExit() {}

    virtual void update() = 0;

    virtual typename Manager::States next(const std::vector<typename Manager::States> &conditions) = 0;
};


template<typename Manager>
State<Manager>::~State() = default;


template<typename Manager>
class StateMachineEngine {
public:
    StateMachineEngine() = default;
    State<Manager> *pCurrentState{nullptr};
    typename Manager::States targetState{};  // Usually triggered by the user's input
    std::vector<typename Manager::States> conditions{};
    // List of available states
    std::unordered_map<typename Manager::States, std::unique_ptr<State<Manager>>> states{};

    template<typename T>
    void addState(std::unique_ptr<T> state)
    requires std::is_base_of_v<State<Manager>, T> {
        auto [it, inserted] = states.emplace(state->stateID, std::move(state));

        if (!pCurrentState && inserted) {
            pCurrentState = it->second.get();
        }
    }

    void act() const;
    void transition(const typename Manager::States &stateID) {
        auto pNextState = states.at(stateID).get();
        pNextState->pPreviousState = pCurrentState;
        pCurrentState = pNextState;
    }
    void update();
};


template<typename Manager>
void StateMachineEngine<Manager>::act() const {
    if (pCurrentState != nullptr) pCurrentState->update();
}


template<typename Manager>
void StateMachineEngine<Manager>::update() {
    assert(pCurrentState != nullptr);
    pCurrentState->update();
    conditions.clear();
    conditions.push_back(targetState);
    auto newState = pCurrentState->next(conditions);
    if (newState != pCurrentState->stateID) {
        transition(newState);
    }
}

#endif //BONK_GAME_STATE_MACHINE_ENGINE_HPP
