//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_RUNNING_HPP
#define BONK_GAME_RUNNING_HPP

#include "../../../Game/Engines/StateMachine/StateBase.hpp"
#include "../Player.hpp"
#include "States.hpp"


namespace player {
    class Running final : public StateBase<States>{
    public:
        explicit Running(Player *pPlayer) : StateBase(States::RUNNING), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(States::IDLE));
            addEdge(std::make_unique<Edge>(States::WALKING));
            addEdge(std::make_unique<Edge>(States::STOPPING));
            addEdge(std::make_unique<Edge>(States::JUMPING));
        };
        // HOST
        Player *pPlayer{nullptr};

        void update() override {
            if (pPlayer) pPlayer->movement.walk();
        };

    };
}



#endif //BONK_GAME_RUNNING_HPP