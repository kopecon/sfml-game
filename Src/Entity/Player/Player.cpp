//
// Created by Andrew on 13/11/2025.
//

#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Includes/World/World.hpp"


using enum player::StateManager::States;

#pragma region constructors
Player::Player(std::string name) : Entity(std::move(name)){}
Player::Player(std::string name, const Controls &controls) :
Entity(std::move(name)), input(*this, controls), physics(*this), movement(*this), combat(*this), animationManager(*this), stateManager(*this) {
    this->animationManager.engine.animationSheet = {pTexture, {32, 32}};
    this->animationManager.engine.target = &shape;
    animationManager.engine.add(AnimationEntry(IDLE,         2, true));
    animationManager.engine.add(AnimationEntry(WINKING,      2, true));
    animationManager.engine.add(AnimationEntry(WALKING,      4, true));
    animationManager.engine.add(AnimationEntry(RUNNING,      8, true));
    animationManager.engine.add(AnimationEntry(CROUCHING,    6, true));
    animationManager.engine.add(AnimationEntry(JUMPING,      8, false));
    animationManager.engine.add(AnimationEntry(DYING,        8, false));
    animationManager.engine.add(AnimationEntry(DISAPPEARING, 4, false));
    animationManager.engine.add(AnimationEntry(ATTACKING,    8, false));
}
#pragma endregion

sf::Vector2f Player::getSize() const {
    return shape.getGlobalBounds().size;
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

void Player::initShapeSize() {
    shape.setSize(static_cast<sf::Vector2f>(pTexture->getSize()));
}

sf::Shape *Player::getShape() {
    return &shape;
}

sf::Texture *Player::getTexture() {
    return &pWorld->pGame->textures.player;
}

void Player::init() {
    Entity::init();
    const sf::Vector2f sizeRatio = getWindowToShapeSizeRatio() * height;
    pShape->setScale(sizeRatio);
}

void Player::update() {
    input.update();
    physics.update();
    stateManager.update();
    animationManager.update();
}

player::StateManager::States Player::getStateID() const {
    return stateManager.engine.pCurrentState->stateID;
}
