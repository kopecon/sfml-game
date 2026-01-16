#include "../../../Includes/Entity/Scenery/Scenery.hpp"
#include "../../../Includes/Game/Game.hpp"
#include "../../../Includes/World/World.hpp"


namespace scenery {

#pragma region constructors
    Scenery::Scenery(World &world, const entityID ID) :
        Entity(world, ID)
    {}

    Scenery::Scenery(World &world, const entityID ID, std::string name) :
        Entity(world, ID, std::move(name))
    {}
#pragma endregion

    void Scenery::scaleToWindowWidth() {
        const sf::Vector2f windowToRenderRatio = hd::divide(
            world.game.video.getWindowSize(),
            render.getGlobalBounds().size
        );
        render.setScale({
            render.getScale().x * static_cast<float>(stretchFactor) * windowToRenderRatio.x,
            render.getScale().y
        });
    }

    void Scenery::repeatToWidth() const {
        // FIXME: not properly recursive yet
        for (const auto &pComposite : render.composites) {
            for (const auto &pSubComposite : pComposite->composites) {
                if (const auto pSprite = pSubComposite->getSprite()) {
                    const int texWidth = static_cast<int>(pSprite->getTexture().getSize().x);
                    const int texHeight = static_cast<int>(pSprite->getTexture().getSize().y);
                    const int renderWidth = static_cast<int>(render.getGlobalBounds().size.x);
                    pSprite->setTextureRect(
                        sf::IntRect({0, 0}, {std::max(stretchFactor*texWidth, renderWidth), texHeight}));
                }
            }
        }
    }

    void Scenery::setCamera() {
        pCamera = &game.video.camera;
    }

    void Scenery::loop() {
        // This could be improved, but I don't care anymore... it works well enough now.
        if (!pCamera) setCamera();
        else {
            const auto cameraCenter = pCamera->view.getCenter();
            const auto cameraWidth = pCamera->view.getSize().x / pCamera->zoom;

            const auto cameraRBorder = cameraCenter.x + cameraWidth / 2.f;
            const auto cameraLBorder = cameraCenter.x - cameraWidth / 2.f;

            const auto renderRBorder = position.x + render.getGlobalBounds().size.x / 2.f;
            const auto renderLBorder = position.x - render.getGlobalBounds().size.x / 2.f;

            if (cameraRBorder > renderRBorder || cameraLBorder < renderLBorder) {
                position = {
                    cameraCenter.x,
                    position.y};
            }
        }
    }

    void Scenery::init() {
        Entity::init();
        // scaleToWindowWidth();
        // repeatToWidth();
    }

    void Scenery::update() {
        // loop();
        render.update();
    }
}
