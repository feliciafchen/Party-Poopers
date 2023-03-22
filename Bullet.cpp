//
// Created by Felicia Chen on 12/5/22.
//

#include "Bullet.h"

Bullet::Bullet() {
    setRadius(35);
    setFillColor(sf::Color::Yellow);
    velocity = {0, 0};
}

void Bullet::move() {
    sf::CircleShape::move(velocity);
}

const sf::Vector2f &Bullet::getVelocity() const {
    return velocity;
}

void Bullet::setVelocity(const sf::Vector2f &velocity) {
    Bullet::velocity = velocity;
}

void Bullet::hit(Hittable &target) {
    sf::FloatRect b = target.getGlobalBounds();
    if(!checkState(HIDDEN) && b.intersects(sf::CircleShape::getGlobalBounds())
       && clock.getElapsedTime().asMilliseconds() > 200)
    {
        target.getHit(10);
        enableState(HIDDEN);
        clock.restart();
    }
}
