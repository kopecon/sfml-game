//
// Created by Andrew on 14/11/2025.
//

#ifndef BONK_GAME_CAMERA_HPP
#define BONK_GAME_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"


class Camera {
public:
    explicit Camera(const sf::Window &window);
    const sf::Window &window{};
    sf::View view{};
    Entity *pTarget{};

    void followTarget();
};

#endif //BONK_GAME_CAMERA_HPP