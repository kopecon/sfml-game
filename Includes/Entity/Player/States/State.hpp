//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_STATE_HPP
#define BONK_GAME_STATE_HPP
#include <iostream>
#include "StateManager.hpp"
// #include "../Player.hpp"



class State {
protected:
    StateManager *pStateManager{nullptr};
public:
    virtual ~State();

    explicit State(StateManager *stateManager, const StateManager::States &state);

    StateManager::States state{};

    template<typename T>
    void enter();

    virtual void act() = 0;

    virtual void exit(const StateManager::States &condition);
};

template<typename T>
void State::enter() {
    // std::cout << pStateManager->pPlayer->name << " Entering State: " << typeid(*this).name() << "\n";
    pStateManager->state = state;
    pStateManager->pState = std::make_unique<T>(pStateManager);
}

#endif //BONK_GAME_STATE_HPP
