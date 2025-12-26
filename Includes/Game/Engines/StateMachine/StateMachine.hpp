//
// Created by Andrew on 08/12/2025.
//

#ifndef BONK_GAME_STATE_MACHINE_HPP
#define BONK_GAME_STATE_MACHINE_HPP
#include <cassert>
#include <iostream>
#include <memory>
#include <unordered_map>

#include "StateBase.hpp"
#include "../../../Entity/Player/Player.hpp"


template<typename States>
class StateMachine {
    void _enter(StateBase<States> *pState) {
        pCurrentState = pState;
        pCurrentState->onEnter();
    }
    void _exit(StateBase<States> *pState) {
        pCurrentState->onExit();
        pPreviousState = pState;
    }
public:
    #pragma region constructors
    StateMachine() = default;

    explicit StateMachine(Entity *pEntity) : pEntity(pEntity){}
    #pragma endregion

    // HOST
    Entity *pEntity{nullptr};
    // STATE ACCESS
    StateBase<States> *pCurrentState{nullptr};
    StateBase<States> *pPreviousState{nullptr};
    States desiredStateID{};
    // LIST OF AVAILABLE STATES
    std::unordered_map<States, std::unique_ptr<StateBase<States>>> states{};

    StateBase<States>* getState(States &stateID) {
        auto it = states.find(stateID);
        if (it == states.end()) {
            std::cout << "Desired state " << static_cast<int>(stateID) << " not implemented!\n";
            return nullptr;
        }
        return it->second.get();
    }

    template<typename T>
    void addState(std::unique_ptr<T> pState)
    requires std::is_base_of_v<StateBase<States>, T> {

        auto [it, inserted] = states.emplace(pState->stateID, std::move(pState));

        if (!pCurrentState && inserted) {
            pCurrentState = it->second.get();
        }
    }

    void transition() {
        auto newStateID = pCurrentState->next(desiredStateID);
        if (newStateID != pCurrentState->stateID) {
            if (const auto newState = getState(newStateID)) {
                _exit(pCurrentState);
                _enter(newState);
            }
        }
    }

    void update() {
        // 1. Check if we are in a state
        assert(pCurrentState != nullptr);
        // 2. Do state action
        pCurrentState->update();
        // 3. Transition to the new state
        transition();
    }
};

#endif //BONK_GAME_STATE_MACHINE_HPP