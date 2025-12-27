//
// Created by Andrew on 27/12/2025.
//

#ifndef BONK_GAME_STATE_SET_BASE_HPP
#define BONK_GAME_STATE_SET_BASE_HPP
#include <string_view>

template<typename> struct StateSetTraits;

template<typename Derived>
struct StateSetBase {
    using ID = typename StateSetTraits<Derived>::Enum;

    static std::string_view name(const ID state) {
        return StateSetTraits<Derived>::name(state);
    }
};

template<typename T>
concept StateSetConcept = requires(typename T::ID id) {
    {T::name(id)} -> std::convertible_to<std::string_view>;
};

#endif //BONK_GAME_STATE_SET_BASE_HPP