//
// Created by Andrew on 06/12/2025.
//

#ifndef BONK_GAME_MOVEMENT_COMPONENT_HPP
#define BONK_GAME_MOVEMENT_COMPONENT_HPP
#include <functional>


class Player;

class MovementComponent {
public:
    MovementComponent();
    explicit MovementComponent(Player &player);;

    Player *pPlayer{nullptr};

    void turn() const;
    std::function<void()> walk;
    void walkLeft() const;
    void walkRight() const;
    void brake() const;
    void jump() const;
};


#endif //BONK_GAME_MOVEMENT_COMPONENT_HPP