//
// Created by Andrew on 06/12/2025.
//

#include "../../../Includes/Entity/Player/MovementComponent.hpp"
#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Utils/utils.hpp"
#include "../../../Includes/World/World.hpp"


MovementComponent::MovementComponent() = default;

MovementComponent::MovementComponent(Player &player): pPlayer(&player) {}

void MovementComponent::turn() const {
    brake();
    if (areClose(pPlayer->physics.velocity.x, 0.f, 10.f)) {
        pPlayer->shape.setScale({-pPlayer->shape.getScale().x, pPlayer->shape.getScale().y});
        pPlayer->facingRight = !pPlayer->facingRight;
    }
}

void MovementComponent::walkLeft() const {
    if (pPlayer->facingRight) turn();
    else pPlayer->physics.accelerate(-pPlayer->physics.speed);
}

void MovementComponent::walkRight() const {
    if (!pPlayer->facingRight) turn();
    else pPlayer->physics.accelerate(pPlayer->physics.speed);
}

void MovementComponent::brake() const {
    pPlayer->physics.accelerate({0.f, pPlayer->physics.velocity.y});
}

void MovementComponent::jump() const {
    if (pPlayer->physics.position.y + pPlayer->getSize().y / 2.f >= pPlayer->pWorld->groundLevel) {
        pPlayer->physics.velocity.y = -pPlayer->pWorld->gravity*pPlayer->physics.speed.y/2500.f;  // Magic number is tweaked experimentally
    }
}
