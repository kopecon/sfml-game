//
// Created by Andrew on 07/12/2025.
//

#include "Idle.hpp"
#include "Walking.hpp"
#include <iostream>

#include "../Player.hpp"
#include "../StateManager.hpp"

Idle::Idle(): State("IDLE") {}

Idle::Idle(StateManager *stateManager): State(stateManager, "IDLE") {}

void Idle::enter() {
    State::enter();
    pStateManager->pState = std::make_unique<Idle>(pStateManager);
}

void Idle::act() {
    pStateManager->state = States::IDLE;
    pStateManager->pPlayer->movement.brake();
}

void Idle::exit(const States &conditions) {
    if (conditions == States::WALKING) {
        State::exit(conditions);
        std::make_unique<Walking>(pStateManager)->enter();
    }
}
