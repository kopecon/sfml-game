//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_JUMPING_HPP
#define BONK_GAME_JUMPING_HPP

#include "../../../Game/Engines/StateMachine/StateBase.hpp"
#include "../Player.hpp"
#include "States.hpp"

namespace player {
    class Jumping final : public StateBase<States> {
    public:
        explicit Jumping(Player *pPlayer) : StateBase(States::JUMPING), pPlayer(pPlayer) {
            auto grounded = [this] {
                return this->pPlayer->physics.isGrounded();
            };

            addEdge(std::make_unique<Edge>(grounded, States::IDLE));
            addEdge(std::make_unique<Edge>(grounded, States::WALKING));
            addEdge(std::make_unique<Edge>(grounded, States::STOPPING));
            addEdge(std::make_unique<Edge>(grounded, States::RUNNING));
        }
        // HOST
        Player *pPlayer{nullptr};

        void onEnter() override {
            pPlayer->movement.jump();
        };

        void update() override {};
    };
}



#endif //BONK_GAME_JUMPING_HPP