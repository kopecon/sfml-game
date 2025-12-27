//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_JUMPING_HPP
#define BONK_GAME_JUMPING_HPP

#include "../../../Game/Engines/StateMachine/State.hpp"
#include "../Player.hpp"
#include "StateSet.hpp"

namespace player {
    class Jumping final : public State<StateSet> {
    public:
        explicit Jumping(Player *pPlayer) : State(StateSet::ID::JUMPING), pPlayer(pPlayer) {
            auto grounded = [this] {
                return this->pPlayer->physics.isGrounded();
            };

            addEdge(std::make_unique<Edge>(grounded, StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(grounded, StateSet::ID::WALKING));
            addEdge(std::make_unique<Edge>(grounded, StateSet::ID::STOPPING));
            addEdge(std::make_unique<Edge>(grounded, StateSet::ID::RUNNING));
        }
        // HOST
        Player *pPlayer{nullptr};

        void onEnter() override {
            pPlayer->movement.jump();
        };
    };
}



#endif //BONK_GAME_JUMPING_HPP