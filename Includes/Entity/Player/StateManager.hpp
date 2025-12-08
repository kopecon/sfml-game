//
// Created by Andrew on 06/12/2025.
//

#ifndef BONK_GAME_STATE_MANAGER_HPP
#define BONK_GAME_STATE_MANAGER_HPP
#include <memory>
#include "States/State.hpp"


class Player;

class StateManager {
public:
    StateManager();
    explicit StateManager(Player &player);

    Player *pPlayer{nullptr};
    std::unique_ptr<State> pState{nullptr};
    State::States state{State::States::IDLE};

    void act() const;
    void update() const;
};


#endif //BONK_GAME_STATE_MANAGER_HPP