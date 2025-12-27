//
// Created by Andrew on 27/12/2025.
//

#ifndef BONK_GAME_WINKING_HPP
#define BONK_GAME_WINKING_HPP
#include "PlayerState.hpp"
#include "../Player.hpp"


namespace player {
    class Winking final : public PlayerState {
    public:
        explicit Winking(Player *pPlayer)
            : PlayerState(pPlayer, StateSet::ID::WINKING) {
            auto wetEyes = [pPlayer]{return pPlayer->eyeDryness <= 0;};
            addEdge(std::make_unique<Edge>(wetEyes, StateSet::ID::IDLE));
            addAction([pPlayer] {
                pPlayer->eyeDryness -= 1;
            });
        }
    };
}

#endif //BONK_GAME_WINKING_HPP
