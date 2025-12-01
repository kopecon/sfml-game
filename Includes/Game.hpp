//
// Created by Andrew on 29/11/2025.
//

#ifndef BONK_GAME_GAME_HPP
#define BONK_GAME_GAME_HPP

#include "VideoComponent.hpp"
#include "AudioComponent.hpp"
#include "World.hpp"


class World;

class Game {
public:
#pragma region constructors
    Game();
    explicit Game(const char* &title) :
    title(title),
    videoComponent(title)
    {}
#pragma endregion
    // META DATA
    const char* title{};

    // COMPONENTS
    VideoComponent videoComponent;
    AudioComponent audioComponent;
    sf::Clock clock;
    float dt{};

    World *pWorld{};

    void update() {
        dt = clock.restart().asSeconds(); // seconds since last frame
        videoComponent.update();
    }
};

#endif //BONK_GAME_GAME_HPP