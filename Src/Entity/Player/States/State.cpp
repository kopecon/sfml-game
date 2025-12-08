//
// Created by Andrew on 07/12/2025.
//

#include "../../../../Includes/Entity/Player/States/State.hpp"
#include "../../../../Includes/Entity/Player/Player.hpp"

#include <iostream>


State::~State() = default;

State::State(std::string name) : name(std::move(name)) {
}

State::State(StateManager *stateManager, std::string name): pStateManager(stateManager), name(std::move(name)) {}

void State::enter() {
    std::cout << pStateManager->pPlayer->name << " Entering State: " << this->name << "\n";
}

void State::exit(const States &conditions) {
    std::cout << pStateManager->pPlayer->name << " Exiting State: " << this->name << "\n";
}

