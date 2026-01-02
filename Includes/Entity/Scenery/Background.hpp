//
// Created by Andrew on 13/11/2025.
//

#ifndef BONK_GAME_BACKGROUND_HPP
#define BONK_GAME_BACKGROUND_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Scenery.hpp"


namespace scenery {
    class Background final : public Scenery {
    public:

#pragma region constructors
        explicit Background(World &world, entityID ID);
        explicit Background(World &world, entityID ID, std::string name);
        [[nodiscard]] std::string getClassName() const override;
#pragma endregion

        void buildRender();

    };
}

#endif //BONK_GAME_BACKGROUND_HPP