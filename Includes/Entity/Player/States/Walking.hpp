//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_WALKING_HPP
#define BONK_GAME_WALKING_HPP

#include "../../../Game/Engines/StateMachine/State.hpp"
#include "StateSet.hpp"
#include "../Player.hpp"


namespace player {
    class Walking final : public State<StateSet> {
    public:
        explicit Walking(Player *pPlayer) : State(StateSet::ID::WALKING), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(StateSet::ID::RUNNING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::STOPPING));
            addAction([pPlayer]{pPlayer->movement.walk();});
        };

        // HOST
        Player *pPlayer{nullptr};
    };
}



#endif //BONK_GAME_WALKING_HPP