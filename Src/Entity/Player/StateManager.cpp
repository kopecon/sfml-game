//
// Created by Andrew on 06/12/2025.
//

#include "../../../Includes/Entity/Player/StateManager.hpp"
#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Includes/World/World.hpp"


StateManager::StateManager() = default;

StateManager::StateManager(Player &player): pPlayer(&player), walking(player) {}

void StateManager::declareState() {
    using enum States;
    const States desiredState = pPlayer->input.update();
    if (pPlayer->health <= 0) {
        state = DYING;
        return;
    }
    if (state == JUMPING) {
        if (pPlayer->physics.position.y  + pPlayer->getSize().y / 2.f >= pPlayer->pWorld->groundLevel) {
            state = IDLE;
        }
    }
    else if (state == ATTACKING) {
        if (pPlayer->animation.completed(ATTACKING)) {
            this->state=IDLE;
        }
    }
    else {  // ACTIONS NEED TO BE SORTED BY PRIORITY
        if (desiredState == JUMPING) {
            state = JUMPING;
        }
        else if (desiredState == ATTACKING) {
            state = ATTACKING;
        }
        else if (desiredState == WALKING) {
            state = WALKING;
            changeState(&walking);
        }
        else if (desiredState == RUNNING) {
            state = RUNNING;
        }
        else if (desiredState == STOPPING) {
            state = STOPPING;
        }
        else if (desiredState == IDLE) {
            if (std::fabs(pPlayer->physics.velocity.x) > 0) {
                state = BRAKING;
            }
            else state = IDLE;
        }
    }
}

void StateManager::act() {
    using enum States;
    switch (state) {
        case IDLE: {
            break;
        }
        case WINKING: {
            break;
        }
        case WALKING: {
            pPlayer->physics.speed = pPlayer->physics.walkingSpeed;
            // pPlayer->movement.walk();
            takeAction();
            break;
        }
        case RUNNING: {
            pPlayer->physics.speed = pPlayer->physics.runningSpeed;
            pPlayer->movement.walk();
            break;
        }
        case CROUCHING: {
            break;
        }
        case JUMPING: {
            pPlayer->movement.jump();
            break;
        }
        case DISAPPEARING: {
            break;
        }
        case DYING: {
            pPlayer->combat.die();
            break;
        }
        case ATTACKING: {
            pPlayer->combat.attack();
            break;
        }
        case BRAKING: {
            pPlayer->movement.brake();
            break;
        }
        case STOPPING: {
            pPlayer->movement.brake();
            break;
        }
        default: {
        }
    }
}
