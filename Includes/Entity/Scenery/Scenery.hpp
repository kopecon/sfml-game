//
// Created by Andrew on 01/12/2025.
//

#ifndef BONK_GAME_SCENERY_HPP
#define BONK_GAME_SCENERY_HPP

#include "../../Game/Camera.hpp"
#include "../../Entity/Entity.hpp"


namespace scenery {
    class Scenery : public entity::Entity {
    public:

#pragma region constructors
        explicit Scenery(World &world, entityID ID);
        explicit Scenery(World &world, entityID ID, std::string name);

        void scaleToWindowWidth();
#pragma endregion

        const int stretchFactor = 3;
        const Camera *pCamera{};   //TODO: Make protected

        void repeatToWidth() const;

        void setCamera();

        void loop();

        void init() override;

        void update() override;
    };
}



#endif //BONK_GAME_SCENERY_HPP