//
// Created by Andrew on 08/12/2025.
//

#ifndef BONK_GAME_STOPPING_HPP
#define BONK_GAME_STOPPING_HPP

#include "../../../Game/Engines/StateMachine/State.hpp"
#include "../Player.hpp"
#include "StateSet.hpp"

namespace player {
    class Stopping final : public State<StateSet> {
    public:
        explicit Stopping(Player *pPlayer) : State(StateSet::ID::STOPPING), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(StateSet::ID::WALKING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::RUNNING));
            addAction([pPlayer]{pPlayer->movement.brake();});
        };

        // HOST
        Player *pPlayer{nullptr};
    };
}



#endif //BONK_GAME_STOPPING_HPP