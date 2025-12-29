//
// Created by Andrew on 29/12/2025.
//

#ifndef BONK_GAME_STATE_MANAGER_HPP
#define BONK_GAME_STATE_MANAGER_HPP
#include "States/StateSet.hpp"
#include "../../Game/Engines/StateMachine/StateMachine.hpp"
#include "States/Idle.hpp"
#include "States/Attacking.hpp"
#include "States/Jumping.hpp"
#include "States/Running.hpp"
#include "States/Stopping.hpp"
#include "States/Walking.hpp"
#include "States/Winking.hpp"


namespace player {
    class StateManager {
    public:
        explicit StateManager(Player &player);

        StateMachine<StateSet> stateMachine{};

        void update();
    };
}


#endif //BONK_GAME_STATE_MANAGER_HPP