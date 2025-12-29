//
// Created by Andrew on 29/12/2025.
//

#include "../../../Includes/Entity/Player/StateManager.hpp"

player::StateManager::StateManager(Player &player) {
    stateMachine.addState(std::make_unique<Idle     >(player));
    stateMachine.addState(std::make_unique<Jumping  >(player));
    stateMachine.addState(std::make_unique<Running  >(player));
    stateMachine.addState(std::make_unique<Walking  >(player));
    stateMachine.addState(std::make_unique<Stopping >(player));
    stateMachine.addState(std::make_unique<Attacking>(player));
    stateMachine.addState(std::make_unique<Winking  >(player));
    stateMachine.setVerbose();
}

void player::StateManager::update() {
    stateMachine.update();
}
