//
// Created by Andrew on 27/11/2025.
//

#ifndef BONK_GAME_GROUND_HPP
#define BONK_GAME_GROUND_HPP

#include "../Includes/Entity.hpp"
#include "../Includes/Camera.hpp"


class Ground final : public Entity {
public:
    sf::Vector2f size{};
    sf::Shape *shapes[2]{};
    sf::Texture *pTexture{};
    sf::Texture *pTextureTop{};
    sf::RectangleShape body{};
    sf::RectangleShape top{};

    Ground();

    Ground(sf::Texture &groundTextureRef, sf::Texture &topGroundTextureRef, const sf::Vector2u &window, const float &groundLevel);

    void loop(const Camera &camera);

    void update(const float &dt) override;
};


#endif //BONK_GAME_GROUND_HPP