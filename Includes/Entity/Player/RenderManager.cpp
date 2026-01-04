//
// Created by Andrew on 02/01/2026.
//

#include "RenderManager.hpp"
#include "../../Game/Game.hpp"
#include "Player.hpp"


namespace player {
    RenderManager::RenderManager(Player &player): player(player) {
        const auto &texture = player.game.textures.player;

        auto shape = std::make_unique<sf::RectangleShape>(sf::Vector2f(texture.getSize()));

        shape->setTexture(&texture);
        shape->setTextureRect(sf::IntRect({0, 0}, {32, 32}));
        shape->setOrigin(shape->getGeometricCenter());

        auto composite = std::make_unique<entity::ShapeComposite>();
        composite->addShape(std::move(shape));
        // composite->enlarge({1.f, player.height});
        player.render.addComposite(std::move(composite));
    }
} // player