//
// Created by Andrew on 27/11/2025.
//

#ifndef BONK_GAME_WORLD_HPP
#define BONK_GAME_WORLD_HPP
#include <iostream>
#include <vector>
#include "Entity.hpp"
#include "Player.hpp"
#include "SFML/Graphics/RenderWindow.hpp"


namespace sf {
    class RectangleShape;
}

class Entity;

class World {
    std::vector<Entity*> entities{};
public:
    void add(Entity &entity);

    template<typename T>
    std::vector<T*> findTypes();

    void remove(const Entity *entity);

    void draw(sf::RenderWindow &window) const;

    void update(const float &dt);
};

template<typename T>
std::vector<T *> World::findTypes() {
    std::vector<T*> listOfTypes{};
    for (auto *entity : entities) {
        if (auto it = dynamic_cast<T*>(entity)) {
            listOfTypes.emplace(listOfTypes.end(), it);
        }
    }
    return listOfTypes;
}

#endif //BONK_GAME_WORLD_HPP
