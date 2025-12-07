//
// Created by Andrew on 06/12/2025.
//

#ifndef BONK_GAME_STATE_MANAGER_HPP
#define BONK_GAME_STATE_MANAGER_HPP

#include <iostream>

#include "CombatComponent.hpp"
#include "States/Walking.hpp"


class Player;

class StateManager {
public:
    enum class States {
        IDLE,
        WINKING,
        WALKING,
        RUNNING,
        CROUCHING,
        JUMPING,
        DISAPPEARING,
        DYING,
        ATTACKING,
        BRAKING,
        STOPPING,
    };
    StateManager();
    explicit StateManager(Player &player);

    Player *pPlayer{nullptr};
    State *pState{nullptr};
    States state{States::IDLE};

    Walking walking{};
    void declareState();

    void act();

    void changeState(State *newState) {
        pState = newState;
    }

    void takeAction() {
        if (pState != nullptr) pState->act();
    }
};


#endif //BONK_GAME_STATE_MANAGER_HPP