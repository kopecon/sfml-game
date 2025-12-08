//
// Created by Andrew on 07/12/2025.
//

#ifndef BONK_GAME_STATE_HPP
#define BONK_GAME_STATE_HPP
#include <string>

class StateManager;
class Player;


class State {
protected:
    StateManager *pStateManager{nullptr};
public:
    enum class States {
        IDLE,
        WINKING,
        WALKING,
        RUNNING,
        CROUCHING,
        JUMPING,
        DISAPPEARING,
        DYING,
        ATTACKING,
        BRAKING,
        STOPPING,
    };
    virtual ~State();
    explicit State(std::string name);
    explicit State(StateManager *stateManager, std::string name);

    std::string name{};

    virtual void enter();

    virtual void act() = 0;

    virtual void exit(const States &conditions);
};

#endif //BONK_GAME_STATE_HPP
