//
// Created by Andrew on 08/12/2025.
//

#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Stopping.hpp"


using namespace player;

Stopping::Stopping(StateManager *stateManager): State(stateManager, StateManager::States::STOPPING) {}


void Stopping::update() {
    pManager->pPlayer->movement.brake();
}

StateManager::States Stopping::next(const std::vector<StateManager::States> &conditions) {
    if (conditions.back()  == StateManager::States::IDLE) {
        return StateManager::States::IDLE;
    }
    if (conditions.back()  == StateManager::States::WALKING) {
        return StateManager::States::WALKING;
    }
    if (conditions.back() == StateManager::States::RUNNING) {
        return StateManager::States::RUNNING;
    }
    if (conditions.back() == StateManager::States::JUMPING) {
        return StateManager::States::JUMPING;
    }
    return stateID;
}
