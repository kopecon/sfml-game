//
// Created by Andrew on 26/12/2025.
//

#ifndef BONK_GAME_STATES_HPP
#define BONK_GAME_STATES_HPP

namespace player {
    struct StateSet {
        enum class Enum {
            NONE = -1,
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
        static std::string_view name(const Enum &state) {
            using enum Enum;
            switch (state) {
                case NONE:           return "NONE";
                case IDLE:           return "IDLE";
                case WINKING:        return "WINKING";
                case WALKING:        return "WALKING";
                case RUNNING:        return "RUNNING";
                case CROUCHING:      return "CROUCHING";
                case JUMPING:        return "JUMPING";
                case DISAPPEARING:   return "DISAPPEARING";
                case DYING:          return "DYING";
                case ATTACKING:      return "ATTACKING";
                case BRAKING:        return "BRAKING";
                case STOPPING:       return "STOPPING";
                default:             return "UNKNOWN";
            }
        }
    };
    using States = StateSet::Enum;
}

#endif //BONK_GAME_STATES_HPP