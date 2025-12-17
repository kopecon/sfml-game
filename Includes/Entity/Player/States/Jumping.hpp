//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_JUMPING_HPP
#define BONK_GAME_JUMPING_HPP
#include "../../../Game/Engines/StateMachineEngine.hpp"


class Jumping final : public State<player::StateManager> {
public:

    explicit Jumping(player::StateManager *stateManager);

    bool inAir{false};

    void update() override;

    player::StateManager::States next(const std::vector<player::StateManager::States> &conditions) override;

};


#endif //BONK_GAME_JUMPING_HPP