//
// Created by Andrew on 07/12/2025.
//

#include "Walking.hpp"
#include "Idle.hpp"

#include "../Player.hpp"
#include "../StateManager.hpp"

void Walking::enter() {
    State::enter();
    pStateManager->pState = std::make_unique<Walking>(pStateManager);
}

void Walking::act() {
    pStateManager->pPlayer->physics.speed = pStateManager->pPlayer->physics.walkingSpeed;
    pStateManager->pPlayer->movement.walk();
    pStateManager->pPlayer->stateManager.state = States::WALKING;
}

void Walking::exit(const States &conditions) {
    if (conditions == States::IDLE) {
        State::exit(conditions);
        std::make_unique<Idle>(pStateManager)->enter();
    }
}
