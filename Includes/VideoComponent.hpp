//
// Created by Andrew on 29/11/2025.
//

#ifndef BONK_GAME_VIDEOCOMPONENT_HPP
#define BONK_GAME_VIDEOCOMPONENT_HPP
#include <string>
#include <SFML/Graphics.hpp>

#include "Camera.hpp"


class VideoComponent {
public:
    explicit VideoComponent(const std::string &title)
    : title(title),
    settings(24, 8, 4, 3, 0),   // depth, stencil, antiAlias, major, minor
    window(sf::VideoMode(initScreenSize), title, sf::Style::Default, windowState, settings),
    camera(window)
    {
        window.setFramerateLimit(fps);
    }

    // METADATA
    std::string title{};

    // VIDEO SETTINGS
    sf::ContextSettings settings;
    const sf::Vector2u initScreenSize{800, 600};
    unsigned int fps{144};
    sf::State windowState = sf::State::Windowed;  // Initial state when game starts

    sf::RenderWindow window;
    Camera camera;

    void recreate() {
        window.create(sf::VideoMode::getDesktopMode(), title, sf::Style::Default, windowState, settings);
    }

    void onClose(const sf::Event::Closed&)
    {
        // Pre-closing procedures implement here.
        window.close();
    }

    void onKeyPressed(const sf::Event::KeyPressed& keyPressed) {
        switch (keyPressed.scancode)
        {
            case sf::Keyboard::Scancode::Escape : window.close(); break;
            case sf::Keyboard::Scancode::U :
            {
                if (windowState == sf::State::Windowed) {
                    windowState = sf::State::Fullscreen;
                }
                else if (windowState == sf::State::Fullscreen) {
                    windowState = sf::State::Windowed;
                }
                // Recreate the window
                recreate();
            }
            default: {
            }
        }
    }

    void update() {
        window.handleEvents(
            [&](const sf::Event::Closed &event){onClose(event);},
            [&](const sf::Event::KeyPressed &keyPressed){onKeyPressed(keyPressed);}
        );

        // Camera
        camera.followTarget();

        // Update the view to follow player
        window.setView(camera.view);
    }
};


#endif //BONK_GAME_VIDEOCOMPONENT_HPP