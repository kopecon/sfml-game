//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_WALKING_HPP
#define BONK_GAME_WALKING_HPP

#include "PlayerState.hpp"
#include "../../../Game/Engines/StateMachine/State.hpp"
#include "StateSet.hpp"
#include "../Player.hpp"


namespace player {
    class Walking final : public PlayerState {
    public:
        explicit Walking(Player *pPlayer) : PlayerState(pPlayer, StateSet::ID::WALKING) {
            addEdge(std::make_unique<Edge>(StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(StateSet::ID::RUNNING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::STOPPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::ATTACKING));
            addAction([pPlayer]{pPlayer->movement.walk();});
        }
    };
}



#endif //BONK_GAME_WALKING_HPP