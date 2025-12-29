//
// Created by Andrew on 29/12/2025.
//

#include "PlayerRenderComponent.hpp"
#include "Player.hpp"


namespace player {
    PlayerRenderComponent::PlayerRenderComponent(Player &player):
        player(player) {}

    void PlayerRenderComponent::initShapeSize() {
        shape.setSize(static_cast<sf::Vector2f>(player.pTexture->getSize()));
    }
} // player