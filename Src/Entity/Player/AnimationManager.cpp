//
// Created by Andrew on 06/12/2025.
//

#include "../../../Includes/Entity/Player/AnimationManager.hpp"
#include "../../../Includes/Entity/Player/Player.hpp"


AnimationManager::AnimationManager() = default;

AnimationManager::AnimationManager(Player &player): pPlayer(&player) {}

void AnimationManager::selectAnimation() const {
    using enum StateManager::States;
    switch (pPlayer->state.state) {
        case JUMPING : {
            pPlayer->animation.set(JUMPING);
            pPlayer->animation.animationSet[JUMPING].fps = std::fabs(pPlayer->physics.walkingSpeed.y / pPlayer->physics.speed.y)*24.f;
            break;
        }
        case WALKING : {
            pPlayer->animation.set(WALKING);
            pPlayer->animation.pCurrentAnimation->fps = std::fabs(pPlayer->physics.velocity.x / pPlayer->physics.walkingSpeed.x) * static_cast<float>(pPlayer->animation.pCurrentAnimation->framesPerRow) * 2.f;
            break;
        }
        case RUNNING : {
            pPlayer->animation.set(RUNNING);
            pPlayer->animation.pCurrentAnimation->fps = std::fabs(pPlayer->physics.velocity.x / pPlayer->physics.runningSpeed.x) * static_cast<float>(pPlayer->animation.pCurrentAnimation->framesPerRow) * 2.f;
            break;
        }
        case ATTACKING : {
            pPlayer->animation.set(ATTACKING);
            pPlayer->animation.pCurrentAnimation->fps = static_cast<float>(pPlayer->animation.pCurrentAnimation->framesPerRow) * 3.f;
            break;
        }
        case DYING : {
            pPlayer->animation.set(DYING);
            // animation.pCurrentAnimation->fps = static_cast<float>(animation.pCurrentAnimation->framesPerRow) * 3.f;
            break;
        }
        default: {
            pPlayer->animation.set(IDLE);
        }
    }
}
