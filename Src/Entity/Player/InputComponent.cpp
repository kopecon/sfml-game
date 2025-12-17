//
// Created by Andrew on 20/11/2025.
//

#include "../../../Includes/Entity/Player/InputComponent.hpp"
#include "../../../Includes/Entity/Player/Player.hpp"


#pragma region constructors
player::InputComponent::InputComponent() = default;
player::InputComponent::InputComponent(Player &player, const Controls &controls) : pPlayer(&player), controls(controls) {}
#pragma endregion

    void player::InputComponent::update() const {
    const bool left = sf::Keyboard::isKeyPressed(controls.left);
    const bool right = sf::Keyboard::isKeyPressed(controls.right);
    const bool jump = sf::Keyboard::isKeyPressed(controls.jump);
    const bool run = sf::Keyboard::isKeyPressed(controls.run);
    const bool attack = sf::Keyboard::isKeyPressed(controls.attack);
    using enum StateManager::States;

    // ACTIONS NEED TO BE SORTED BY PRIORITY
    if (jump) pPlayer->stateManager.engine.targetState = JUMPING;
    else if (attack) pPlayer->stateManager.engine.targetState = ATTACKING;
    else if (left && right) pPlayer->stateManager.engine.targetState = STOPPING;
    else if (left) {
        pPlayer->movement.walk = [&]{pPlayer->movement.walkLeft();};
        if (run) pPlayer->stateManager.engine.targetState = RUNNING;
        else pPlayer->stateManager.engine.targetState = WALKING;
        }
    else if (right) {
        pPlayer->movement.walk = [&]{pPlayer->movement.walkRight();};
        if (run) pPlayer->stateManager.engine.targetState = RUNNING;
        else pPlayer->stateManager.engine.targetState = WALKING;
        }
    else
    pPlayer->stateManager.engine.targetState = IDLE;
}