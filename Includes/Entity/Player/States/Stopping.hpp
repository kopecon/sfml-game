//
// Created by Andrew on 08/12/2025.
//

#ifndef BONK_GAME_STOPPING_HPP
#define BONK_GAME_STOPPING_HPP

#include "../../../Game/Engines/StateMachine/StateBase.hpp"
#include "../Player.hpp"
#include "States.hpp"

namespace player {
    class Stopping final : public StateBase<States> {
    public:
        explicit Stopping(Player *pPlayer) : StateBase(States::STOPPING), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(States::IDLE));
            addEdge(std::make_unique<Edge>(States::WALKING));
            addEdge(std::make_unique<Edge>(States::JUMPING));
            addEdge(std::make_unique<Edge>(States::RUNNING));
        };

        // HOST
        Player *pPlayer{nullptr};

        void update() override {
            pPlayer->movement.brake();
        };
    };
}



#endif //BONK_GAME_STOPPING_HPP