//
// Created by Andrew on 26/12/2025.
//

#ifndef BONK_GAME_IDLE_HPP
#define BONK_GAME_IDLE_HPP

#include "../../../Game/Engines/StateMachine/State.hpp"
#include "../Player.hpp"
#include "StateSet.hpp"


namespace player {
    class Idle final : public State<States> {
    public:
        explicit Idle(Player *pPlayer) : State(States::IDLE), pPlayer(pPlayer) {
            addEdge(std::make_unique<Edge>(States::WALKING));
            addEdge(std::make_unique<Edge>(States::RUNNING));
            addEdge(std::make_unique<Edge>(States::STOPPING));
            addEdge(std::make_unique<Edge>(States::JUMPING));
            addAction([pPlayer]{pPlayer->movement.brake();});
        }
        // HOST
        Player *pPlayer{nullptr};
    };
}

#endif //BONK_GAME_IDLE_HPP