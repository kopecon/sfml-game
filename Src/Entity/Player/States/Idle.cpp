//
// Created by Andrew on 07/12/2025.
//

#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Idle.hpp"


using namespace player;

Idle::Idle(StateManager *stateManager) :
State(stateManager, StateManager::States::IDLE) {}

void Idle::update() {
    pManager->pPlayer->movement.brake();
}

StateManager::States Idle::next(const std::vector<StateManager::States> &conditions) {
    if (conditions.back() == StateManager::States::WALKING) {
        return StateManager::States::WALKING;
    }
    if (conditions.back() == StateManager::States::JUMPING) {
        return StateManager::States::JUMPING;
    }
    if (conditions.back() == StateManager::States::RUNNING) {
        return StateManager::States::RUNNING;
    }
    if (conditions.back() == StateManager::States::STOPPING) {
        return StateManager::States::STOPPING;
    }
    return stateID;
}
