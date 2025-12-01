//
// Created by Andrew on 29/11/2025.
//

#ifndef BONK_GAME_GAME_HPP
#define BONK_GAME_GAME_HPP

#include "../Includes/VideoComponent.hpp"
#include "../Includes/AudioComponent.hpp"
#include "../Includes/Camera.hpp"


class Game {
public:
    Game();
    explicit Game(const char* &title) :
    title(title),
    videoComponent(VideoComponent(title)),
    camera(Camera(videoComponent.window))
    {}

    float dt{};
    const char* title{};
    VideoComponent videoComponent;
    AudioComponent audioComponent;

    sf::Clock clock;
    Camera camera;
};

#endif //BONK_GAME_GAME_HPP