//
// Created by Felicia Chen on 12/5/22.
//

#include <iostream>
#include "PlayerHealth.h"

void PlayerHealth::hit(int damage) {
    if(health.getSize().x - damage/4 > 0)
    {
        health.setSize({health.getSize().x - damage/4, health.getSize().y});
    }
    else
    {
        health.setSize({0, health.getSize().y});
    }
}

void PlayerHealth::heal(int healAmt) {
    if(health.getSize().x + healAmt/4 < totalHealth.getSize().x)
    {
        health.setSize({health.getSize().x + healAmt/4, totalHealth.getSize().y});
    }
    else
    {
        makeFullHealth();
    }
}

PlayerHealth::PlayerHealth()
{
}

PlayerHealth::PlayerHealth(AnimatedSprite &player)
: PlayerHealth(100, 100, player)
{
}

PlayerHealth::PlayerHealth(int health, int totalHealth, AnimatedSprite& player) {

    this -> totalHealth.setSize({static_cast<float>(totalHealth/4), player.getGlobalBounds().height / 10});
    this -> health.setSize({static_cast<float>(health/4), player.getGlobalBounds().height / 10});

    this -> health.setFillColor(sf::Color::Red);
    this -> totalHealth.setFillColor(sf::Color::White);
    player.setState(DEAD, false);
    player.setState(HIDDEN, false);
}

void PlayerHealth::makeFullHealth() {
    health.setSize(totalHealth.getSize());
}

void PlayerHealth::makeHealth(int health) {
    if(health <= totalHealth.getSize().x)
    {
        this -> health.setSize({static_cast<float>(health/4), totalHealth.getSize().x});
    }
}

void PlayerHealth::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(totalHealth);
    target.draw(health);
}

void PlayerHealth::move(sf::Vector2f offsetXY) {
    health.move(offsetXY);
    totalHealth.move(offsetXY);
}

void PlayerHealth::setScale(sf::Vector2f scale) {
    health.setScale(scale);
    totalHealth.setScale(scale);
}

sf::FloatRect PlayerHealth::getGlobalBounds() {
    return totalHealth.getGlobalBounds();
}

void PlayerHealth::setPosition(sf::Vector2f position) {
    totalHealth.setPosition(position);
    health.setPosition(position);
}

bool PlayerHealth::isAlive() const{
    if(health.getSize().x/4 <= 0)
    {
        return false;
    }
    return true;
}


