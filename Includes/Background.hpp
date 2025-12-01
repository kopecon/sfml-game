//
// Created by Andrew on 13/11/2025.
//

#ifndef BONK_GAME_BACKGROUND_HPP
#define BONK_GAME_BACKGROUND_HPP
#include <SFML/Graphics.hpp>

#include "Entity.hpp"
#include "Camera.hpp"
#include "World.hpp"

class Background final : public Entity {
public:
    sf::Vector2u size{};
    sf::Texture* pTexture{};
    sf::RectangleShape shape{};
    bool looping{true};

    Background();

    explicit Background(sf::Texture &backgroundTextureRef, const sf::Vector2u &window);

    void loop(const Camera &camera);

    void update() override;
};

#endif //BONK_GAME_BACKGROUND_HPP