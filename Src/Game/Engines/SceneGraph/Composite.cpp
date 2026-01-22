//
// Created by Andrew on 05/01/2026.
//

#include "../../../../Utils/utils.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "../../../../Includes/Game/Engines/SceneGraph/Composite.hpp"

#include <iostream>

#include "../../../../Includes/Game/Engines/AnimationEngine/Animatable.hpp"


#pragma region constructors
Composite::Composite() = default;
#pragma endregion

Animatable * Composite::asAnimatable() {
    return nullptr;
}

void Composite::add(std::unique_ptr<Composite> composite) {
    composite->setOrigin({0.f, 0.f});
    children_.push_back(std::move(composite));
}

void Composite::rename(std::string name) {
    name_ = std::move(name);
}

void Composite::setColor(const sf::Color &color) const {
    // for (const auto &pSprite : getChildren()) {
    // pSprite->setColor(color);
    // }
}

void Composite::showOutline(const sf::Color color) {
    auto bounds = getLocalBounds();
    auto boundary = std::make_unique<sf::RectangleShape>(bounds.size);
    boundary->setPosition(bounds.position);
    boundary->setFillColor(sf::Color::Transparent);
    boundary->setOutlineColor(color);
    boundary->setOutlineThickness(5.f);
    outline_ = std::move(boundary);
}

sf::FloatRect Composite::getLocalBounds() const {
    //CHATGPT SOLUTION
    bool initialized = false;

    sf::Vector2f minPos;
    sf::Vector2f maxPos;

    auto absorb = [&](const sf::FloatRect& r) {
        const sf::Vector2f rMin = r.position;
        const sf::Vector2f rMax = r.position + r.size;

        if (!initialized) {
            minPos = rMin;
            maxPos = rMax;
            initialized = true;
        } else {
            minPos.x = std::min(minPos.x, rMin.x);
            minPos.y = std::min(minPos.y, rMin.y);
            maxPos.x = std::max(maxPos.x, rMax.x);
            maxPos.y = std::max(maxPos.y, rMax.y);
        }
    };

    if (sprite_) {
        absorb(sprite_->getGlobalBounds());
    }

    for (const auto& child : children_) {
        absorb(child->getGlobalBounds());
    }

    if (!initialized)
        return {};

    return { minPos, maxPos - minPos };
}

sf::FloatRect Composite::getGlobalBounds() const {
    return getTransform().transformRect(getLocalBounds());
}


sf::Vector2f Composite::getCenter() const {
    const auto localBounds = getLocalBounds();
    const auto x = localBounds.position.x + localBounds.size.x / 2.f;
    const auto y = localBounds.position.y + localBounds.size.y / 2.f;
    return {x, y};
}

std::string_view Composite::getName() const {
    return name_;
}

std::vector<std::unique_ptr<Composite>>& Composite::getChildren() {
    return children_;
}

bool Composite::play(const float dt) {
    // Own animation
    if (const auto animated = asAnimatable()) {
        animated->animate(dt);
        return true;
    }
    // Children animation
    for (const auto &pChild : children_) {
        pChild->play(dt);
    }
    return false;
}

void Composite::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

    // DRAW SELF
    drawSelf(target, states);

    // DRAW CHILDREN
    for (const auto &child : children_) {
        target.draw(*child, states);
    }
    // DRAW OUTLINE
    if (outline_) {
        target.draw(*outline_, states);
    }
}
