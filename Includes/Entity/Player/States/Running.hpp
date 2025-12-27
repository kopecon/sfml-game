//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_RUNNING_HPP
#define BONK_GAME_RUNNING_HPP

#include "../../../Game/Engines/StateMachine/State.hpp"
#include "../Player.hpp"
#include "StateSet.hpp"


namespace player {
    class Running final : public State<StateSet>{
    public:
        explicit Running(Player *pPlayer) : State(StateSet::ID::RUNNING), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(StateSet::ID::IDLE));
            addEdge(std::make_unique<Edge>(StateSet::ID::WALKING));
            addEdge(std::make_unique<Edge>(StateSet::ID::STOPPING));
            addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
            addAction([pPlayer]{pPlayer->movement.walk();});
        };
        // HOST
        Player *pPlayer{nullptr};
    };
}



#endif //BONK_GAME_RUNNING_HPP