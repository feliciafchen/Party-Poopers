//
// Created by Felicia Chen on 12/5/22.
//

#ifndef SHOOTA_PLAYERHEALTH_H
#define SHOOTA_PLAYERHEALTH_H
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "Position.h"
#include "MouseEvents.h"

class PlayerHealth : public sf::Drawable
{
private:
    sf::RectangleShape health, totalHealth;
public:
    PlayerHealth();
    PlayerHealth(AnimatedSprite& player);
    PlayerHealth(int health, int totalHealth, AnimatedSprite& player);
    void makeFullHealth();
    void makeHealth(int health);
    void hit(int damage);
    void heal(int healAmt);
    void move(sf::Vector2f offsetXY);
    void setScale(sf::Vector2f scale);
    sf::FloatRect getGlobalBounds();
    void setPosition(sf::Vector2f position);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    bool isAlive() const;
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SHOOTA_PLAYERHEALTH_H
