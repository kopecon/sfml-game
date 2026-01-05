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

    void Scenery::setCamera() {
        pCamera = &game.video.camera;
    }

    void Scenery::loop() {
        // FIXME: There is sometimes space between border and ground edge when looping.
        if (pCamera == nullptr) setCamera();
        else {
            const auto cameraCenter = pCamera->view.getCenter();
            const auto cameraWidth = pCamera->view.getSize().x;

            const auto cameraRBorder = cameraCenter.x + cameraWidth / 2.f;
            const auto cameraLBorder = cameraCenter.x - cameraWidth / 2.f;


            for (const auto &pComposite : render.getComposites()) {
                for (const auto &pShape : pComposite->shapes) {
                    const float shapeWidth = pShape->getGlobalBounds().size.x;
                    const auto shapeRBorder = position.x + shapeWidth / 2.f;
                    const auto shapeLBorder = position.x - shapeWidth / 2.f;

                    std::cout << cameraLBorder << " " << cameraRBorder << "\n";
                    std::cout << shapeLBorder << " " << shapeRBorder << "\n";
                    // RIGHT
                    if (cameraRBorder > shapeRBorder) {
                        position = {
                            cameraRBorder-cameraWidth/2.f,
                            position.y};
                    }
                    // LEFT
                    else if (cameraLBorder < shapeLBorder) {
                        position = {
                            cameraLBorder+cameraWidth/2.f,
                            position.y};
                    }
                }
            }
        }
    }

    void Scenery::update() {
        loop();
        render.update();
    }
}
