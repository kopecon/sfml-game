//
// Created by Andrew on 30/12/2025.
//

#ifndef BONK_GAME_RENDER_COMPONENT_HPP
#define BONK_GAME_RENDER_COMPONENT_HPP
#include <memory>
#include <vector>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "Composite.hpp"


namespace entity {
    class Entity;
}


class Render final: public sf::Drawable {
protected:
    std::vector<std::unique_ptr<Composite>> composites{};
    entity::Entity &entity;
    sf::Vector2f scale{1.f, 1.f};

public:
    explicit Render(entity::Entity &entity);

    [[nodiscard]] const std::vector<std::unique_ptr<Composite>>& getComposites() const;

    void stretchToWidth(sf::RectangleShape *pShape) const;

    void repeatToWidth(sf::RectangleShape *pShape) const;

    void addComposite(std::unique_ptr<Composite> composite);

    void setFillColor(const sf::Color &color) const;

    void setScale(const sf::Vector2f &amount);

    sf::Vector2f getScale() const;

    Composite& getComposite(const Composite &composite);

    [[nodiscard]] std::vector<std::unique_ptr<Composite>>& getComposites();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        for (const auto &pComposite : composites) {
            target.draw(*pComposite);
        }
    }

    void init();

    void update() const;
};


#endif //BONK_GAME_RENDER_COMPONENT_HPP