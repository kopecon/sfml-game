//
// Created by Andrew on 05/01/2026.
//

#include "../../../../Includes/Game/Engines/Render/Composite.hpp"
#include "../../../../Utils/utils.hpp"
#include <iostream>


void Composite::addShape(std::unique_ptr<sf::Shape> shape) {
    shapes.push_back(std::move(shape));
}

void Composite::setFillColor(const sf::Color &color) const {
    for (const auto &pShape : shapes) {
        pShape->setFillColor(color);
    }
}

sf::Vector2f Composite::getGeometricalCenter() const {
    //TODO: Implement actual solution
    return shapes.back()->getGeometricCenter();
}

void Composite::enlarge(const float &factor) const {
    for (const auto &pShape : shapes) {
        pShape->setScale(scalar::multiply(pShape->getScale(), factor));
    }
}

void Composite::enlarge(const sf::Vector2f &factor) {
    setScale(hd::multiply(this->getScale(), factor));
}

sf::Shape& Composite::getShape(const sf::Shape &shape) {
    const auto it = std::ranges::find_if(
        shapes,
        [&shape](const std::unique_ptr<sf::Shape>& obj) {
            return obj.get() == &shape;
        });
    if (it == shapes.end()) std::cout << "Shape not found.\n";
    return *it->get();
}
