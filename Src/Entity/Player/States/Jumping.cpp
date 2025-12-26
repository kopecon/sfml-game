//
// Created by Andrew on 07/12/2025.
//

#include "../../../../Includes/Entity/Player/Player.hpp"
#include "../../../../Includes/Entity/Player/States/Jumping.hpp"


using namespace player;

Jumping::Jumping(StateManager *pManager): StateBase(pManager, StateManager::States::JUMPING) {
    addEdge(std::make_unique<Edge>([this](){return this->pManager->pPlayer->physics.isGrounded();}, StateManager::States::IDLE));
    addEdge(std::make_unique<Edge>([this](){return this->pManager->pPlayer->physics.isGrounded();}, StateManager::States::WALKING));
    addEdge(std::make_unique<Edge>([this](){return this->pManager->pPlayer->physics.isGrounded();}, StateManager::States::RUNNING));
    addEdge(std::make_unique<Edge>([this](){return this->pManager->pPlayer->physics.isGrounded();}, StateManager::States::STOPPING));
}

void Jumping::onEnter() {
    StateBase::onEnter();
    pManager->pPlayer->physics.verbose = true;
}

void Jumping::onExit() {
    StateBase::onExit();
    pManager->pPlayer->physics.verbose = false;
}

void Jumping::update() {
    pManager->pPlayer->movement.jump();
}