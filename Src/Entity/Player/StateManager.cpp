//
// Created by Andrew on 06/12/2025.
//

#include "../../../Includes/Entity/Player/StateManager.hpp"
#include "../../../Includes/Entity/Player/StateManager.hpp"
#include "../../../Includes/Entity/Player/StateManager.hpp"
#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Includes/Entity/Player/States/Idle.hpp"
#include "../../../Includes/Entity/Player/States/Jumping.hpp"
#include "../../../Includes/Entity/Player/States/Running.hpp"
#include "../../../Includes/Entity/Player/States/Stopping.hpp"
#include "../../../Includes/Entity/Player/States/Walking.hpp"


player::StateManager::StateManager() = default;

player::StateManager::StateManager(Player &player) : pPlayer(&player), engine(this) {
        // engine.addState(std::make_unique<Idle>(this));
        // engine.addState(std::make_unique<Jumping>(this));
        // engine.addState(std::make_unique<Running>(this));
        // engine.addState(std::make_unique<Stopping>(this));
        // engine.addState(std::make_unique<Walking>(this));
        engine.createState(States::NONE, []{std::cout<< "Update\n";},
                [](const std::vector<States> &) -> States {
                        std::cout<< "Next\n";
                        return States::NONE;
                });

}

void player::StateManager::update() {
        engine.update();
}
