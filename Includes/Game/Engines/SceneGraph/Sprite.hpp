//
// Created by Andrew on 22/01/2026.
//

#ifndef BONK_GAME_SPRITE_HPP
#define BONK_GAME_SPRITE_HPP
#include "Composite.hpp"


class Sprite : public Composite {
protected:
    std::unique_ptr<sf::Sprite> sprite_{nullptr};
public:
    explicit Sprite(const sf::Texture &texture);

private:
    void drawSelf(sf::RenderTarget &target, sf::RenderStates states) const override;;
};


#endif //BONK_GAME_SPRITE_HPP