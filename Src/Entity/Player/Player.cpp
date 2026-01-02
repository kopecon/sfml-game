#include "../../../Includes/Entity/Player/Player.hpp"
#include "../../../Includes/Game/Game.hpp"
#include "../../../Includes/World/World.hpp"


namespace player {
    using enum StateSet::ID;

    #pragma region constructors
    Player::Player(World &world, const entityID ID) :
        Entity(world, ID),
        input(*this),
        physics(*this),
        movement(*this),
        combat(*this),
        renderManager(*this),
        animationManager(*this),
        stateManager(*this) {
    }

    Player::Player(World &world, const entityID ID, const Controls &controls) :
        Entity(world, ID),
        input(*this, controls),
        physics(*this),
        movement(*this),
        combat(*this),
        renderManager(*this),
        animationManager(*this),
        stateManager(*this) {
    }

    Player::Player(World &world, const entityID ID, std::string name) :
        Entity(world, ID, std::move(name)),
        input(*this),
        physics(*this),
        movement(*this),
        combat(*this),
        renderManager(*this),
        animationManager(*this),
        stateManager(*this) {
    }

    Player::Player(World &world, const entityID ID, std::string name, const Controls &controls) : Entity(world, ID,
            std::move(name)),
        input(*this, controls),
        physics(*this),
        movement(*this),
        combat(*this),
        renderManager(*this),
        animationManager(*this),
        stateManager(*this) {
    }
    #pragma endregion

    sf::Vector2f Player::getSize() const {
        return render.getShape().getGlobalBounds().size;
    }

    const State<StateSet>* Player::getState() const {
        return stateManager.stateMachine.pCurrentState;
    }

    void Player::update() {
        input.update();
        physics.update();
        stateManager.update();
        animationManager.update();
        render.update();
    }

    std::string Player::getClassName() const {
        return "Player";
    }
}
