//
// Created by Andrew on 22/01/2026.
//

#include "../../../../Includes/Game/Engines/SceneGraph/Sprite.hpp"

#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Texture.hpp"


Sprite::Sprite(const sf::Texture& texture):
    sprite_(std::make_unique<sf::Sprite>(texture)) {
    rename("sprite");
}

Colorable* Sprite::asColorable() {
    return this;
}

void Sprite::applyColor(const sf::Color color) {
    sprite_->setColor(color);
}

sf::Sprite& Sprite::getSprite() const {
    // TODO: possibly bad practice... temporary solution?
    return *sprite_;
}

std::optional<sf::FloatRect> Sprite::getSelfGlobalBounds() const {
    return sprite_->getGlobalBounds();
}

void Sprite::drawSelf(sf::RenderTarget &target, const sf::RenderStates states) const {
    target.draw(*sprite_, states);
}
