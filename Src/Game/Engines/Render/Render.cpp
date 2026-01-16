#include "../../../../Includes/Game/Game.hpp"
#include "../../../../Includes/Game/Engines/Render/Render.hpp"
#include "../../../../Includes/Entity/Entity.hpp"


Render::Render(entity::Entity &entity):entity(entity) {}

void Render::init() {
    setScale(hd::multiply(getScale(), entity.game.video.getWindowToScreenRatio()));
}

void Render::update() {
    setPosition(entity.position);
}
