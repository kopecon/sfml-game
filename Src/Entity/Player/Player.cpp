//
// Created by Andrew on 13/11/2025.
//

#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Includes/World/World.hpp"


using enum StateManager::States;

#pragma region constructors
Player::Player(std::string name) : Entity(std::move(name)){}
Player::Player(std::string name, const Controls &controls) :
Entity(std::move(name)), input(*this, controls), physics(*this), movement(*this), combat(*this), animation(*this), state(*this) {
    this->animation.animationSheet = {pTexture, {32, 32}};
    this->animation.target = &shape;
    animation.add(AnimationEntry(IDLE,         2, true));
    animation.add(AnimationEntry(WINKING,      2, true));
    animation.add(AnimationEntry(WALKING,      4, true));
    animation.add(AnimationEntry(RUNNING,      8, true));
    animation.add(AnimationEntry(CROUCHING,    6, true));
    animation.add(AnimationEntry(JUMPING,      8, false));
    animation.add(AnimationEntry(DYING,        8, false));
    animation.add(AnimationEntry(DISAPPEARING, 4, false));
    animation.add(AnimationEntry(ATTACKING,    8, false));
}
#pragma endregion

sf::Vector2f Player::getSize() const {
    return shape.getGlobalBounds().size;
}

sf::Vector2f Player::getPosition() const {
    return shape.getPosition();
}

void Player::setPosition(const sf::Vector2f &position) {
    shape.setPosition(position);
    physics.position = getPosition();
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
    physics.acceleration = {0.f, pWorld->gravity};  // Reset acceleration
    state.declareState();
    animation.selectAnimation();
    state.act();
    physics.update();
    animation.update(pWorld->pGame->time.dt);
}
