//
// Created by Andrew on 29/12/2025.
//

#include "../../../../Includes/Entity/Player/States/StateManager.hpp"
#include "../../../../Includes/Entity/Player/States/Idle.hpp"
#include "../../../../Includes/Entity/Player/States/Jumping.hpp"
#include "../../../../Includes/Entity/Player/States/Walking.hpp"
#include "../../../../Includes/Entity/Player/States/Running.hpp"
#include "../../../../Includes/Entity/Player/States/Stopping.hpp"
#include "../../../../Includes/Entity/Player/States/Attacking.hpp"
#include "../../../../Includes/Entity/Player/States/Winking.hpp"


player::StateManager::StateManager(Player &player) {
    stateMachine.createState<Idle>(player);
    stateMachine.createState<Jumping>(player);
    stateMachine.createState<Running>(player);
    stateMachine.createState<Walking>(player);
    stateMachine.createState<Stopping>(player);
    stateMachine.createState<Winking>(player);
    stateMachine.createState<Attacking>(player);
    stateMachine.setVerbose();
}

void player::StateManager::update() {
    stateMachine.update();
}
