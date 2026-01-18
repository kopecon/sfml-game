//
// Created by Andrew on 18/01/2026.
//

#ifndef BONK_GAME_ANIMATION_HPP
#define BONK_GAME_ANIMATION_HPP
#include <functional>
#include "SFML/System/Vector2.hpp"


template<typename AnimationEnum>
requires (std::is_enum_v<AnimationEnum>)
class Animation {
public:
    enum class Status {
        READY, PLAYING, END, COMPLETED
    };

#pragma region constructors
    Animation() = default;

    Animation(const AnimationEnum &id, const int &framesPerRow, const bool &looping=true) :
    ID(id),
    fpr(framesPerRow),
    fps(static_cast<float>(framesPerRow)),
    spf(1.f/fps),
    looping(looping)
    {}
#pragma endregion

#pragma region operators
    bool operator!=(const Animation &other) const {
        return this->ID != other.ID;
    };

    bool operator==(const Animation &other) const {
        return this->ID == other.ID;
    };

    struct Hash {
        size_t operator()(const Animation& anim) const noexcept {
            return std::hash<AnimationEnum>()(anim.ID);
        }
    };
#pragma endregion

    AnimationEnum ID{0};  // Represents row index starting from 0;
    sf::Vector2i frameIndex = {0, static_cast<int>(ID)};
    float timer{0.0f};  // tracks elapsed time
    unsigned fpr{};  // frames per row
    float    fps{};  // frames per second
    float    spf{};  // seconds per frame
    bool started{false};
    bool finished{false};
    bool looping{true};
    Status state{Status::READY};

    void update(const float &dt) {
        if (state == Status::END) {
            state = Status::COMPLETED;
            return;
        }
        state = Status::PLAYING;
        timer += dt;
        // When it is the time to move to the next frame
        if (timer >= spf) {
            frameIndex.x += 1;
            timer = 0.f;  // Reset timer
        }
        // Evaluate the end of animationManager
        if (frameIndex.x+1 > fpr) {
            // LOOP
            if (looping) frameIndex.x = 0;
            // DONT LOOP
            else {
                state = Status::END;
                frameIndex.x = fpr-1;
            }
        }
    };
};


#endif //BONK_GAME_ANIMATION_HPP