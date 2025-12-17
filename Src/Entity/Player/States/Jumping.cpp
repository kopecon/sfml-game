//
// Created by Andrew on 07/12/2025.
//

#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Jumping.hpp"


using namespace player;

Jumping::Jumping(StateManager *stateManager): State(stateManager, StateManager::States::JUMPING) {}


void Jumping::update() {
    if (!inAir) {
        pManager->pPlayer->movement.jump();
        inAir = true;
    }
}

StateManager::States Jumping::next(const std::vector<StateManager::States> &conditions) {
    if (pManager->pPlayer->physics.velocity.y == 0 && inAir) {
        // RESET JUMPING ANIMATION TODO:FIND CLEANER WAY
        pManager->pPlayer->animationManager.engine.animationSet[StateManager::States::JUMPING].frameIndex.x = 0;
        inAir = false;
        if (conditions.back() == StateManager::States::IDLE)
            return StateManager::States::IDLE;
        if (conditions.back() == StateManager::States::WALKING)
            return StateManager::States::WALKING;
        if (conditions.back() == StateManager::States::RUNNING)
            return StateManager::States::RUNNING;
    }
    return stateID;
}
