//
// Created by Andrew on 08/12/2025.
//

#ifndef BONK_GAME_STOPPING_HPP
#define BONK_GAME_STOPPING_HPP

#include "PlayerState.hpp"
#include "../../../Game/Engines/StateMachine/State.hpp"
#include "../Player.hpp"
#include "StateSet.hpp"

namespace player {
    class Stopping final : public PlayerState {
    public:
        explicit Stopping(Player *pPlayer) : PlayerState(pPlayer, StateSet::ID::STOPPING) {
            addEdge(std::make_unique<Edge>(StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(StateSet::ID::WALKING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::RUNNING));
            addEdge(std::make_unique<Edge>(StateSet::ID::ATTACKING));
            addAction([pPlayer]{pPlayer->movement.brake();});
        }
    };
}



#endif //BONK_GAME_STOPPING_HPP