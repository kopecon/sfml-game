//
// Created by Andrew on 27/11/2025.
//

#ifndef BONK_GAME_ENTITY_HPP
#define BONK_GAME_ENTITY_HPP

#include <SFML/Graphics/Shape.hpp>

class Entity {
public:
    virtual ~Entity() = default;

    sf::Shape *pShape{nullptr};
    std::vector<sf::Shape*> pShapes{};

    virtual void update(const float &dt) = 0;

    bool operator==(const Entity &other) const {
        return this == &other;
    }
    bool operator!=(const Entity &other) const {
        return this != &other;
    }
};


#endif //BONK_GAME_ENTITY_HPP