//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_RUNNING_HPP
#define BONK_GAME_RUNNING_HPP

#include "PlayerState.hpp"
#include "../../../Game/Engines/StateMachine/State.hpp"
#include "../Player.hpp"
#include "StateSet.hpp"


namespace player {
    class Running final : public PlayerState {
    public:
        explicit Running(Player *pPlayer) : PlayerState(pPlayer, StateSet::ID::RUNNING) {
            addEdge(std::make_unique<Edge>(StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(StateSet::ID::WALKING));
            addEdge(std::make_unique<Edge>(StateSet::ID::STOPPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::ATTACKING));
            addAction([pPlayer]{pPlayer->movement.walk();});
        }
    };
}



#endif //BONK_GAME_RUNNING_HPP