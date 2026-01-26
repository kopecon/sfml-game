
#include "../../../../Includes/Entity/Player/States/Idle.hpp"
#include "../../../../Includes/Entity/Player/Player.hpp"


player::Idle::Idle(Player &player): PlayerState(player, StateSet::ID::IDLE) {
    // EDGES
    addEdge(std::make_unique<Edge>(StateSet::ID::WALKING));
    addEdge(std::make_unique<Edge>(StateSet::ID::RUNNING));
    addEdge(std::make_unique<Edge>(StateSet::ID::STOPPING));
    addEdge(std::make_unique<Edge>(StateSet::ID::JUMPING));
    addEdge(std::make_unique<Edge>(StateSet::ID::ATTACKING));
    addEdge(std::make_unique<Edge>(StateSet::ID::CONCENTRATING));
    // CONDITION
    auto dryEyes = [&player] {return player.getEyeDryness() >= 100;};
    addEdge(std::make_unique<Edge>(dryEyes, StateSet::ID::WINKING));
    // ACTION
    addAction([&player] {
        player.setEyeDryness(player.getEyeDryness() + 0.1f);
        player.getMovement().brake();
    });
}
