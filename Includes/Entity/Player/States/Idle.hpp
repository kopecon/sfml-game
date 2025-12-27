//
// Created by Andrew on 26/12/2025.
//

#ifndef BONK_GAME_IDLE_HPP
#define BONK_GAME_IDLE_HPP

#include "PlayerState.hpp"
#include "../../../Game/Engines/StateMachine/State.hpp"
#include "../Player.hpp"
#include "StateSet.hpp"


namespace player {
    class Idle final : public PlayerState {
    public:
        explicit Idle(Player *pPlayer) : PlayerState(pPlayer, StateSet::ID::IDLE) {
            addEdge(std::make_unique<Edge>(StateSet::ID::WALKING));
            addEdge(std::make_unique<Edge>(StateSet::ID::RUNNING));
            addEdge(std::make_unique<Edge>(StateSet::ID::STOPPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::ATTACKING));
            auto dryEyes = [pPlayer] {return pPlayer->eyeDryness >= 100;};
            addEdge(std::make_unique<Edge>(dryEyes, StateSet::ID::WINKING));
            addAction([pPlayer] {
                pPlayer->eyeDryness += 0.1;
                pPlayer->movement.brake();
            });
        }
    };
}

#endif //BONK_GAME_IDLE_HPP