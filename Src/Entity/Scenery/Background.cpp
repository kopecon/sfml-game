//
// Created by Andrew on 13/11/2025.
//

#include "../../../Includes/Entity/Scenery/Background.hpp"
#include "../../../Includes/World/World.hpp"

#include <iostream>


Background::Background(const char* name) : Scenery(name){}

void Background::initShapeSize() {
    shape.setSize(static_cast<sf::Vector2f>(pTexture->getSize()));
    const sf::Vector2f sizeRatio = {
        static_cast<float>(pWorld->pGame->video.windowSize.x) / static_cast<float>(pTexture->getSize().x),
        static_cast<float>(pWorld->pGame->video.windowSize.y) / static_cast<float>(pTexture->getSize().y),
    };
    pShape->setScale(sizeRatio);
}

sf::Shape * Background::getShape() {
    return &shape;
}

sf::Texture * Background::getTexture() {
    return &pWorld->pGame->textures.background;
}

void Background::init() {
    Scenery::init();
}
