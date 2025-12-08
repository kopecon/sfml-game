//
// Created by Andrew on 07/12/2025.
//

#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Running.hpp"
#include "../../../../Includes/Entity/Player/States/Stopping.hpp"
#include "../../../../Includes/Entity/Player/States/Idle.hpp"
#include "../../../../Includes/Entity/Player/States/Walking.hpp"
#include "../../../../Includes/Entity/Player/States/Jumping.hpp"


Running::Running(StateManager *stateManager): State(stateManager, StateManager::States::RUNNING) {
}


void Running::act() {
    pStateManager->pPlayer->movement.speed = pStateManager->pPlayer->movement.runningSpeed;
    pStateManager->pPlayer->movement.walk();
}

void Running::exit(const StateManager::States &condition) {
    if (condition == StateManager::States::IDLE) {
        State::exit(condition);
        enter<Idle>();
    }
    else if (condition == StateManager::States::WALKING) {
        State::exit(condition);
        enter<Walking>();
    }
    else if (condition == StateManager::States::JUMPING) {
        State::exit(condition);
        enter<Jumping>();
    }
    else if (condition == StateManager::States::STOPPING) {
        State::exit(condition);
        enter<Stopping>();
    }
}
