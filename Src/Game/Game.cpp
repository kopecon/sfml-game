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

World* Game::createWorld(std::string name) {
    auto pWorld = std::make_unique<World>(*this, std::move(name));
    auto [it, inserted] = worlds_.emplace(pWorld->name, std::move(pWorld));
    pCurrentWorld_ = it->second.get();
    return it->second.get();
}

World* Game::getWorld(std::string name) {
    const auto NAME = text::up(std::move(name));
    const auto it = worlds_.find(NAME);
    if (it == worlds_.end())
        return nullptr;
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
