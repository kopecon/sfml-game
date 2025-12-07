//
// Created by Andrew on 07/12/2025.
//

#include "Walking.hpp"
#include "../Player.hpp"


Walking::Walking() : State("Walking") {}

Walking::Walking(Player &player): State(player, "Walking") {}

void Walking::act() {
    pPlayer->movement.walk();
}
