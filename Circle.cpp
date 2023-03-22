//
// Created by Felicia Chen on 11/22/22.
//

#include "Circle.h"

void Circle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN))
        target.draw(circle);
}

Circle::Circle() : circle(50)
{

}
