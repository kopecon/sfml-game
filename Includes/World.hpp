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
    void add(Entity &entity) {
        entities.emplace(entities.end(), &entity);
    }

    template<typename T>
    std::vector<T*> findTypes() {
        std::vector<T*> listOfTypes{};
        for (auto *entity : entities) {
            if (auto it = dynamic_cast<T*>(entity)) {
                listOfTypes.emplace(listOfTypes.end(), it);
            }
        }
        return listOfTypes;
    }

    void remove(const Entity &entity) {
        // If the element is found, erase it
        if (const auto it = std::ranges::find(entities, &entity); it != entities.end()) {
            entities.erase(it);
        }
    }

    void draw(sf::RenderWindow &window) const {
        for (const auto *entity : entities) {
            if (!entity->pShapes.empty()) {
                for (const auto *shape : entity->pShapes) {
                    window.draw(*shape);
                }
            }
            else window.draw(*entity->pShape);
        }
    }

    void update(const float &dt) const {
        for (auto *entity : entities) {
            entity->update(dt);
        }
    }
};

#endif //BONK_GAME_WORLD_HPP