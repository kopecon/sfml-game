//
// Created by Andrew on 05/01/2026.
//

#ifndef BONK_GAME_COMPOSITE_HPP
#define BONK_GAME_COMPOSITE_HPP
#include <memory>
#include <vector>

#include "SFML/Graphics/Drawable.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/Graphics/Shape.hpp"
#include "SFML/Graphics/Transformable.hpp"


class Composite final : public sf::Drawable, public sf::Transformable {
public:
    Composite() = default;

    std::vector<std::unique_ptr<sf::Shape>> shapes{};

    void addShape(std::unique_ptr<sf::Shape> shape);

    void setFillColor(const sf::Color &color) const;

    sf::Vector2f getGeometricalCenter() const;

    void enlarge(const float &factor) const;

    void enlarge(const sf::Vector2f &factor);

    sf::Shape& getShape(const sf::Shape &shape);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
        states.transform *= getTransform(); // getTransform() is defined by sf::Transformable

        for (const auto &pShape : shapes) {
            // apply the entity's transform -- combine it with the one that was passed by the caller

            // apply the texture
            states.texture = pShape->getTexture();

            // you may also override states.shader or states.blendMode if you want

            // draw the vertex array
            target.draw(*pShape, states);
        }
    }
};


#endif //BONK_GAME_COMPOSITE_HPP