//
// Created by Andrew on 30/12/2025.
//

#ifndef BONK_GAME_RENDER_COMPONENT_HPP
#define BONK_GAME_RENDER_COMPONENT_HPP
#include "Composite.hpp"



namespace entity {
    class Entity;
}


class Render {
protected:
    entity::Entity &entity_;
    Composite root_{};

public:
    explicit Render(entity::Entity &entity);

    void setRoot(Composite &composite) {
        root_ = std::move(composite);
    }

    Composite& getRoot() {
        return root_;
    }

    void loop() const;

    void update();
};


#endif //BONK_GAME_RENDER_COMPONENT_HPP