//
// Created by Andrew on 02/01/2026.
//

#include "../../../Includes/Entity/Player/RenderManager.hpp"
#include "../../../Includes/Game/Game.hpp"
#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Includes/Entity/Player/PlayerSprite.hpp"
#include "../../../Includes/Game/Engines/Render/AnimatedComposite.hpp"
#include "../../../Includes/World/World.hpp"


namespace player {
    RenderManager::RenderManager(Player &player) : player(player) {
        // PLAYER SPRITE
        auto &texture = player.game.textures.player;
        auto animationSheet = std::make_unique<AnimationSheet>(texture, sf::Vector2u(32, 32));
        auto animationSheet1 = std::make_unique<AnimationSheet>(texture, sf::Vector2u(32, 32));
        auto animationSheet2 = std::make_unique<AnimationSheet>(texture, sf::Vector2u(32, 32));
        auto animationSheet3 = std::make_unique<AnimationSheet>(texture, sf::Vector2u(32, 32));
        auto animationSheet4 = std::make_unique<AnimationSheet>(texture, sf::Vector2u(32, 32));

        auto playerSprite = std::make_unique<PlayerSprite>(player, std::move(animationSheet));

        playerSprite->getSprite().setScale(hd::divide(player.getCharacterSize(), playerSprite->getGlobalBounds().size));
        playerSprite->rename("PlayerSprite");

        auto testRootComposite = std::make_unique<Composite>();
        // TEST SPRITE
        auto testComposite1 = std::make_unique<PlayerSprite>(player, std::move(animationSheet1));
        auto testComposite2 = std::make_unique<PlayerSprite>(player, std::move(animationSheet2));
        auto testComposite3 = std::make_unique<PlayerSprite>(player, std::move(animationSheet3));
        auto testComposite4 = std::make_unique<PlayerSprite>(player, std::move(animationSheet4));
        float distance = 60;
        testComposite1->getSprite().move({-distance, -distance});
        testComposite2->getSprite().move({ distance, -distance});
        testComposite3->getSprite().move({-distance,  distance});
        testComposite4->getSprite().move({ distance,  distance});
        testComposite1->rename("LT");
        testComposite2->rename("RT");
        testComposite3->rename("LB");
        testComposite4->rename("RB");

        testRootComposite->add(std::move(testComposite1));
        testRootComposite->add(std::move(testComposite2));
        testRootComposite->add(std::move(testComposite3));
        testRootComposite->add(std::move(testComposite4));
        testRootComposite->showOutline();
        // RENDER
        player.render.changeRoot(std::move(playerSprite));
        auto &root = player.render.getRoot();
        root.add(std::move(testRootComposite));
        root.setOrigin(player.render.getRoot().getCenter());
        root.showOutline(sf::Color::Blue);
    }
} // player