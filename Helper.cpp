//
// Created by Felicia Chen on 11/22/22.
//

#include "Helper.h"

void Helper::output(const sf::FloatRect &bound) {
}

void Helper::output(const sf::Vector2f &bound) {
    std::cout << "x: " << bound.x << ", y: " << bound.y;
}
