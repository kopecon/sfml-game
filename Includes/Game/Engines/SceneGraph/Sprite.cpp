//
// Created by Andrew on 22/01/2026.
//

#include "Sprite.hpp"
#include "SFML/Graphics/RenderTarget.hpp"


Sprite::Sprite(const sf::Texture& texture):
    sprite_(std::make_unique<sf::Sprite>(texture)) {}

void Sprite::drawSelf(sf::RenderTarget &target, sf::RenderStates states) const {
    states.texture = &sprite_->getTexture();
    target.draw(*sprite_, states);
}
