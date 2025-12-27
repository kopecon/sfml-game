//
// Created by Andrew on 27/12/2025.
//

#ifndef BONK_GAME_ATTACKING_HPP
#define BONK_GAME_ATTACKING_HPP
#include "PlayerState.hpp"

namespace player {
    class Attacking final : public PlayerState {
    public:
        Attacking(Player *pPlayer)
            : PlayerState(pPlayer, StateSet::ID::ATTACKING) {
            addEdge(std::make_unique<Edge>(StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(StateSet::ID::RUNNING));
            addEdge(std::make_unique<Edge>(StateSet::ID::WALKING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::STOPPING));
            addEnterAction([]{std::cout << "Swush!\n";});
        }
    };
}

#endif //BONK_GAME_ATTACKING_HPP
