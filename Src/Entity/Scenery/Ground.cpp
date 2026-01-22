//
// Created by Andrew on 27/11/2025.
//

#include "../../../Includes/Entity/Scenery/Ground.hpp"
#include "../../../Includes/Game/Game.hpp"
#include "../../../Includes/Game/Engines/SceneGraph/Sprite.hpp"
#include "../../../Includes/World/World.hpp"


namespace scenery {

#pragma region constructors
    Ground::Ground(World &world, const entityID ID, std::string name) :
        Entity(world, ID, std::move(name))
        {
            buildRender();
        }

    std::string Ground::getClassName() {
        return "Ground";
    }
#pragma endregion

    void Ground::buildRender() {
        auto &topTex = game.textures.topGround;
        auto &bottomTex = game.textures.bottomGround;

        topTex.setRepeated(true);
        bottomTex.setRepeated(true);

        auto top = std::make_unique<Sprite>(topTex);
        auto bottom = std::make_unique<Sprite>(bottomTex);

        bottom->move({top->getPosition().x, top->getPosition().y + top->getGlobalBounds().size.y});


//        for (const auto &pSprite : composite->getChildren()) {
//
//            const auto spriteSize = pSprite->getGlobalBounds().size;
//
//            // Make 3 "copies"
//            pSprite->setTextureRect(
//                sf::IntRect({0, 0},
//                    sf::Vector2i(
//                        static_cast<int>(game.video.getWindowSize().x)*3,
//                        static_cast<int>(spriteSize.y)
//                    )
//                )
//            );
//        }

        render.add(std::move(top));
        render.add(std::move(bottom));
        render.setColor(color);
        render.setOrigin({render.getCenter().x, 0});
    }

    void Ground::update() {
        render.loop();
    }
}
