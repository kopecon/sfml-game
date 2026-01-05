#include "../../../../Includes/Game/Engines/Render/Render.hpp"
#include "../../../../Includes/Game/Game.hpp"
#include "../../../../Includes/Entity/Entity.hpp"
#include <iostream>


Render::Render(entity::Entity &entity):entity(entity) {}

const std::vector<std::unique_ptr<Composite>> & Render::getComposites() const {
    return composites;
}

void Render::stretchToWidth(sf::RectangleShape *pShape) const {
    pShape->setSize({
        3*static_cast<float>(entity.game.video.getWindowSize().x),
        pShape->getSize().y
        }
    );
}

void Render::repeatToWidth(sf::RectangleShape *pShape) const {
    stretchToWidth(pShape);
    const int texWidth = static_cast<int>(pShape->getTexture()->getSize().x);
    const int texHeight = static_cast<int>(pShape->getTexture()->getSize().y);
    const int shapeWidth = static_cast<int>(pShape->getGlobalBounds().size.x);
    pShape->setTextureRect(
        sf::IntRect({0, 0}, {std::max(3*texWidth, shapeWidth), texHeight}));  //TODO: Move "3" to looping or somewhere else
}

void Render::addComposite(std::unique_ptr<Composite> composite) {
    composites.push_back(std::move(composite));
}

void Render::setFillColor(const sf::Color &color) const {
    for (const auto &pComposite : composites) {
        for (const auto &pShape : pComposite->shapes) {
            pShape->setFillColor(color);
        }
    }
}

Composite & Render::getComposite(const Composite &composite) {
    const auto it = std::ranges::find_if(
        composites,
        [&composite](const std::unique_ptr<Composite>& obj) {
            return obj.get() == &composite;
        });
    if (it == composites.end()) std::cout << "Composite not found.\n";
    return *it->get();
}

std::vector<std::unique_ptr<Composite>>& Render::getComposites() {
    return composites;
}

void Render::init() const {
    for (const auto &pComposite : composites) {
        pComposite->enlarge(entity.game.video.getWindowToScreenRatio());
    }
}

void Render::update() const {
    for (const auto &pComposite : composites) {
        pComposite->setPosition(entity.position);
    }
}
