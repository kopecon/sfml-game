//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_WALKING_HPP
#define BONK_GAME_WALKING_HPP

#include "../../../Game/Engines/StateMachine/StateBase.hpp"
#include "States.hpp"
#include "../Player.hpp"


namespace player {
    class Walking final : public StateBase<States> {
    public:
        explicit Walking(Player *pPlayer) : StateBase(States::WALKING), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(States::IDLE));
            addEdge(std::make_unique<Edge>(States::RUNNING));
            addEdge(std::make_unique<Edge>(States::JUMPING));
            addEdge(std::make_unique<Edge>(States::STOPPING));
        };

        // HOST
        Player *pPlayer{nullptr};

        void update() override {
            if (pPlayer) pPlayer->movement.walk();
        };
    };
}



#endif //BONK_GAME_WALKING_HPP