//
// Created by Andrew on 20/11/2025.
//

#include "../../../Includes/Entity/Player/InputComponent.hpp"
#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Includes/Entity/Player/States/StateSet.hpp"
#include "../../../Includes/Game/Game.hpp"


#pragma region constructors
player::InputComponent::InputComponent(Player &player) :
    player_(player),
    gameInput_(player.game.getInput())
    {}

player::InputComponent::InputComponent(Player &player, const Controls &controls):
    player_(player),
    gameInput_(player.game.getInput()),
    controls_(controls)
    {}

Controls & player::InputComponent::getControls() {
    return controls_;
}

#pragma endregion

    void player::InputComponent::update() const {
    const bool left        = gameInput_.key(controls_.left       ).down;
    const bool right       = gameInput_.key(controls_.right      ).down;
    const bool jump        = gameInput_.key(controls_.jump       ).down;
    const bool run         = gameInput_.key(controls_.run        ).down;
    const bool attack      = gameInput_.key(controls_.attack     ).down;
    const bool crouch      = gameInput_.key(controls_.crouch     ).down;
    const bool concentrate = gameInput_.key(controls_.concentrate).pressed;

    using enum StateSet::ID;

    // ACTIONS NEED TO BE SORTED BY PRIORITY
    if (jump) player_.setDesiredState(JUMPING);
    else if (attack) player_.setDesiredState(ATTACKING);
    else if (left && right) player_.setDesiredState(STOPPING);
    else if (left) {
    player_.getMovement().setLeftWalkingDirection();
    if (run) player_.setDesiredState(RUNNING);
    else player_.setDesiredState(WALKING);
    }
    else if (right) {
    player_.getMovement().setRightWalkingDirection();
    if (run) player_.setDesiredState(RUNNING);
    else player_.setDesiredState(WALKING);
    }
    else if (concentrate) {
    player_.setDesiredState(CONCENTRATING);
    }
    else if (crouch) {
    player_.setDesiredState(CROUCHING);
    }
    else
    player_.setDesiredState(IDLE);
}