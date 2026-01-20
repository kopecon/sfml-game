//
// Created by Andrew on 20/01/2026.
//

#ifndef BONK_GAME_ANIMATED_SPRITE_HPP
#define BONK_GAME_ANIMATED_SPRITE_HPP
#include "Composite.hpp"


template<EnumSetConcept AnimationSet>
class AnimatedSprite final: public Composite {
public:
    explicit AnimatedSprite(std::unique_ptr<AnimationSheet> animationSheet) {
        sprite_ = std::make_unique<sf::Sprite>(animationSheet->texture);
        sprite_->setTextureRect(sf::IntRect({0, 0}, static_cast<sf::Vector2i>(animationSheet->frameSize)));
        animator.setAnimationSheet(std::move(animationSheet));
    }

    AnimationEngine<AnimationSet> animator{*sprite_};

    void update(const float &dt) {
        animator.update(dt);
    }
};


#endif //BONK_GAME_ANIMATED_SPRITE_HPP