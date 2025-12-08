//
// Created by Andrew on 08/12/2025.
//

#include "../Player.hpp"
#include "Stopping.hpp"
#include "Idle.hpp"
#include "Walking.hpp"
#include "Running.hpp"
#include "Jumping.hpp"


Stopping::Stopping(StateManager *stateManager): State(stateManager, StateManager::States::STOPPING) {}


void Stopping::act() {
    pStateManager->pPlayer->movement.brake();
}

void Stopping::exit(const StateManager::States &condition) {
    if (condition == StateManager::States::IDLE) {
        State::exit(condition);
        std::make_unique<Idle>(pStateManager)->enter<Idle>();
    }
    else if (condition == StateManager::States::WALKING) {
        State::exit(condition);
        std::make_unique<Walking>(pStateManager)->enter<Walking>();
    }
    else if (condition == StateManager::States::RUNNING) {
        State::exit(condition);
        std::make_unique<Running>(pStateManager)->enter<Running>();
    }
    else if (condition == StateManager::States::JUMPING) {
        State::exit(condition);
        std::make_unique<Jumping>(pStateManager)->enter<Jumping>();
    }
}
