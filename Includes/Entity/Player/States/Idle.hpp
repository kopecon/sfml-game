//
// Created by Andrew on 26/12/2025.
//

#ifndef BONK_GAME_IDLE_HPP
#define BONK_GAME_IDLE_HPP

#include "../../../Game/Engines/StateMachine/StateBase.hpp"
#include "../Player.hpp"
#include "States.hpp"


namespace player {
    class Idle final : public StateBase<States> {
    public:
        explicit Idle(Player *pPlayer) : StateBase(States::IDLE), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(States::WALKING));
            addEdge(std::make_unique<Edge>(States::RUNNING));
            addEdge(std::make_unique<Edge>(States::STOPPING));
            addEdge(std::make_unique<Edge>(States::JUMPING));
        }
        // HOST
        Player *pPlayer{nullptr};

        void update() override {
        pPlayer->movement.brake();
        };
    };
}

#endif //BONK_GAME_IDLE_HPP