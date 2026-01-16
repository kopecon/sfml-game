//
// Created by Andrew on 13/11/2025.
//

#include "../../../Includes/Entity/Scenery/Background.hpp"
#include "../../../Includes/Game/Game.hpp"
#include "../../../Includes/World/World.hpp"


namespace scenery {

#pragma region constructors
    Background::Background(World &world, const entityID ID) :
        Scenery(world, ID)
        {
            buildRender();
        }

    Background::Background(World &world, const entityID ID, std::string name) :
        Scenery(world, ID, std::move(name))
        {
            buildRender();
        }

    std::string Background::getClassName() const {
        return "Background";
    }
#pragma endregion

    void Background::buildRender() {
        auto &texture = game.textures.background;
        texture.setRepeated(true);

        auto sprite = std::make_unique<sf::Sprite>(texture);

        render.setSprite(std::move(sprite));
        render.setOrigin(render.getCenter());
    }
}