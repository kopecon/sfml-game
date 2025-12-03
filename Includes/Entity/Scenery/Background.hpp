//
// Created by Andrew on 13/11/2025.
//

#ifndef BONK_GAME_BACKGROUND_HPP
#define BONK_GAME_BACKGROUND_HPP
#include <SFML/Graphics.hpp>

#include "Scenery.hpp"

class Background final : public Scenery {
public:
    sf::RectangleShape shape{};

    explicit Background(const char* name);

    void initShapeSize() override;

    sf::Shape* getShape() override;

    sf::Texture* getTexture() override;

    void init() override;
};

#endif //BONK_GAME_BACKGROUND_HPP