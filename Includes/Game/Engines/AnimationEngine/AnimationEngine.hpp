//
// Created by Andrew on 17/11/2025.
//

#ifndef BONK_GAME_ANIMATION_ENGINE_HPP
#define BONK_GAME_ANIMATION_ENGINE_HPP

#include <functional>
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Animation.hpp"
#include "AnimationSheet.hpp"


template<typename AnimationEnum>
requires (std::is_enum_v<AnimationEnum>)
class AnimationEngine {
public:
#pragma region constructors
    explicit AnimationEngine(sf::Sprite &target, const AnimationSheet &animationSheet) :
        target(target),
        animationSheet(animationSheet)
        {}
#pragma endregion

    sf::Sprite &target;
    AnimationSheet animationSheet;
    Animation<AnimationEnum> *pPreviousAnimation{nullptr};
    Animation<AnimationEnum> *pCurrentAnimation{nullptr};
    std::unordered_map<AnimationEnum, Animation<AnimationEnum>> animationSet;

    [[nodiscard]] sf::IntRect getCurrentFrame() const {
        auto frameCoord = sf::Vector2i(
            pCurrentAnimation->frameIndex.x*animationSheet.frameSize.x,
            pCurrentAnimation->frameIndex.y*animationSheet.frameSize.y
        );
        return {frameCoord, static_cast<sf::Vector2i>(animationSheet.frameSize)};
    }
    void set(const AnimationEnum &animationID) {
        auto *pNewAnimation = &animationSet[animationID];
        if (pCurrentAnimation == nullptr) {
            pCurrentAnimation = pNewAnimation;
        }
        else if (pCurrentAnimation != pNewAnimation) {
            // Stash previous animation
            pPreviousAnimation = pCurrentAnimation;
            // Load desired animation
            pCurrentAnimation = pNewAnimation;
            // Reset the animation
            pCurrentAnimation->frameIndex.x = 0;
            pCurrentAnimation->state = Animation<AnimationEnum>::Status::READY;
        }
    }

    void add(const Animation<AnimationEnum> &animation) {
        animationSet.emplace(animation.ID, animation);

        if (pCurrentAnimation == nullptr) {
            set(animation.ID);
        }
    }

    void onEnd(const AnimationEnum &animationID, const std::function<void()> &function) {
        if (animationSet[animationID].state == Animation<AnimationEnum>::Status::END) {
            function();
        }
    }

    bool completed(const AnimationEnum &animationID) {
        if (animationSet[animationID].state == Animation<AnimationEnum>::Status::COMPLETED) {
            return true;
        }
        return false;
    }

    void update(const float &dt) const {
        pCurrentAnimation->update(dt);
        target.setTextureRect(getCurrentFrame());
    }
};
#endif //BONK_GAME_ANIMATION_ENGINE_HPP