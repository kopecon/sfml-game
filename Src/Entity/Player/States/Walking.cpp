//
// Created by Andrew on 07/12/2025.
//
#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Running.hpp"
#include "../../../../Includes/Entity/Player/States/Walking.hpp"


using namespace player;


Walking::Walking(StateManager *stateManager): State(stateManager, StateManager::States::WALKING) {}

void Walking::update() {
    pManager->pPlayer->movement.speed = pManager->pPlayer->movement.walkingSpeed;
    pManager->pPlayer->movement.walk();
}

StateManager::States Walking::next(const std::vector<StateManager::States> &conditions) {
    if (conditions.back() == StateManager::States::IDLE) {
        return StateManager::States::IDLE;
    }
    if (conditions.back() == StateManager::States::RUNNING) {
        return StateManager::States::RUNNING;
    }
    if (conditions.back() == StateManager::States::JUMPING) {
        return StateManager::States::JUMPING;
    }
    if (conditions.back() == StateManager::States::STOPPING) {
        return StateManager::States::STOPPING;
    }
    return stateID;
}
