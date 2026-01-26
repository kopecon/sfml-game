//
// Created by Andrew on 29/11/2025.
//

#include "../../Includes/Game/Game.hpp"
#include "../../Includes/World/World.hpp"
#include <unordered_map>


Game::Game() = default;

Game::Game(const std::string &title):
title_(title),
video_(title)
{}

World& Game::createWorld(std::string name) {
    auto world = std::make_unique<World>(*this, std::move(name));
    const std::string key = world->name;
    auto [it, inserted] = worlds_.emplace(key, std::move(world));
    World& worldRef = *it->second.get();
    pCurrentWorld_ = &worldRef;  //TODO: temporary
    return worldRef;
}

World* Game::getWorld(std::string name) {
    const auto NAME = text::up(std::move(name));
    const auto it = worlds_.find(NAME);
    if (it == worlds_.end()) {
        std::cerr << "World with name: " << name << " was not found.\n";
        return nullptr;
    }
    return it->second.get();
}

AudioComponent & Game::getAudio() {
    return audio_;
}

VideoComponent & Game::getVideo() {
    return video_;
}

TimeComponent & Game::getTime() {
    return time_;
}

TextureComponent & Game::getTextures() {
    return textures_;
}

PhysicsEngine & Game::getPhysics() {
    return physics_;
}

void Game::update() {
    time_.update();
    // Update entities in the world
    pCurrentWorld_->update();
    video_.update(pCurrentWorld_);
}
