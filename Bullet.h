//
// Created by Felicia Chen on 12/5/22.
//

#ifndef SHOOTA_BULLET_H
#define SHOOTA_BULLET_H
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "Position.h"
#include "MouseEvents.h"
#include "States.h"
#include "PlayerHealth.h"
#include "Hittable.h"

class Bullet : public sf::CircleShape, public States
{
private:
    sf::Clock clock;
    sf::Vector2f velocity;
public:
    Bullet();
    void move();
    const sf::Vector2f &getVelocity() const;
    void setVelocity(const sf::Vector2f &velocity);
    void hit(Hittable& target);
};


#endif //SHOOTA_BULLET_H
