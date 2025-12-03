//
// Created by Andrew on 27/11/2025.
//

#include <utility>
#include "../../Includes/Entity/Entity.hpp"

#include <iostream>

#include "../../Utils/utils.hpp"
#include "../../Includes/World/World.hpp"


Entity::~Entity() = default;

Entity::Entity(std::string name) {
    text::up(name);
    this->name = std::move(name);
}

void Entity::init() {
    std::cout << "Base Init: " << name << " ...Start" << "\n";
    pShape = getShape();
    pTexture = getTexture();
    initShapeSize();
    pShape->setOrigin(pShape->getGeometricCenter());
    pShape->setTexture(pTexture);
    std::cout << "Base Init: " << name << " ...Finish" << "\n\n";
}

void Entity::update() {}

bool Entity::operator==(const Entity &other) const {
    return this == &other;
}

bool Entity::operator!=(const Entity &other) const {
    return this != &other;
}
