//
// Created by Felicia Chen on 12/5/22.
//

#ifndef SHOOTA_MOB_H
#define SHOOTA_MOB_H
#include "AnimatedSprite.h"
#include "SFML/Graphics.hpp"
#include "PlayerHealth.h"
#include "iostream"
#include "Hittable.h"
#include "Player.h"

class Mob : public sf::Drawable, public Hittable
{
private:
    sf::Clock clock;
    AnimatedSprite mob;
    PlayerHealth healthBar;
    sf::Vector2f spawnPoint;
public:
    const sf::Vector2f &getSpawnPoint() const;
    void setSpawnPoint(const sf::Vector2f &spawnPoint);
    sf::Clock deathClock;
    Mob();
    Mob(AnimatedSprite& mob);
    Mob(AnimatedSprite& mob, int health, int totalHealth);
    Mob(int row, int col, const sf::Texture& texture);
    Mob(int row, int col, const sf::Texture& texture, int health, int totalHealth);
    void move(sf::Vector2f player);
    void still();
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition();
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void attack(Player& player);
    void getHit(int damage) override;
    bool isAlive() const;
    void setState(statesEnum state, bool condition);
    bool checkState(statesEnum state) const;
    void setFullHealth();
    void setRandomPosition(sf::Vector2u window);
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    sf::FloatRect getGlobalBounds() const override;
};


#endif //SHOOTA_MOB_H
