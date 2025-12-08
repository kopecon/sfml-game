//
// Created by Andrew on 07/12/2025.
//

#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Idle.hpp"
#include "../../../../Includes/Entity/Player/States/Stopping.hpp"
#include "../../../../Includes/Entity/Player/States/Walking.hpp"
#include "../../../../Includes/Entity/Player/States/Jumping.hpp"
#include "../../../../Includes/Entity/Player/States/Running.hpp"

Idle::Idle(StateManager *stateManager): State(stateManager, StateManager::States::IDLE) {}


void Idle::act() {
    pStateManager->pPlayer->movement.brake();
}

void Idle::exit(const StateManager::States &condition) {
    if (condition == StateManager::States::WALKING) {
        State::exit(condition);
        enter<Walking>();
    }
    else if (condition == StateManager::States::JUMPING) {
        State::exit(condition);
        enter<Jumping>();
    }
    else if (condition == StateManager::States::RUNNING) {
        State::exit(condition);
        enter<Running>();
    }
    else if (condition == StateManager::States::STOPPING) {
        State::exit(condition);
        enter<Stopping>();
    }
}
