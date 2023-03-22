//
// Created by Felicia Chen on 11/22/22.
//

#ifndef FELICIACHENCS3AFINAL_CIRCLE_H
#define FELICIACHENCS3AFINAL_CIRCLE_H
#include "SFML/Graphics.hpp"
#include "States.h"

class Circle : public sf::Drawable, public States
{
private:
    sf::CircleShape circle;
public:
    Circle();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //FELICIACHENCS3AFINAL_CIRCLE_H
