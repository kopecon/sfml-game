//
// Created by Andrew on 26/01/2026.
//

#include "../../../../Includes/Entity/Player/States/Concentrating.hpp"

#include "../../../../Includes/Entity/Player/Player.hpp"

namespace player {
    Concentrating::Concentrating(Player &player) : PlayerState(player, StateSet::ID::CONCENTRATING) {
        // CONDITIONS
        auto exit = [&]{return sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::C);};
        // EDGES
        addEdge(std::make_unique<Edge>(exit, StateSet::ID::IDLE));
        // ACTIONS
        auto colorPlayer = [&]{player.render.setColor(sf::Color::Cyan);};
        auto resetColor = [&]{player.render.setColor(sf::Color::White);};
        addEnterAction(colorPlayer);
        addExitAction(resetColor);
    }
} // player