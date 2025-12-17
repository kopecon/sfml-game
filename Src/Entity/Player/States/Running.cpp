//
// Created by Andrew on 07/12/2025.
//

#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Running.hpp"


using namespace player;

Running::Running(StateManager *stateManager): State(stateManager, StateManager::States::RUNNING) {
}


void Running::update() {
    pManager->pPlayer->movement.speed = pManager->pPlayer->movement.runningSpeed;
    pManager->pPlayer->movement.walk();
}

StateManager::States Running::next(const std::vector<StateManager::States> &conditions) {
    if (conditions.back() == StateManager::States::IDLE) {
        return StateManager::States::IDLE;
    }
    if (conditions.back() == StateManager::States::WALKING) {
        return StateManager::States::WALKING;
    }
    if (conditions.back() == StateManager::States::JUMPING) {
        return StateManager::States::JUMPING;
    }
    if (conditions.back() == StateManager::States::STOPPING) {
        return StateManager::States::STOPPING;
    }
    return stateID;
}
