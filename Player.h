//
// Created by Felicia Chen on 11/30/22.
//

#ifndef SHOOTA_PLAYER_H
#define SHOOTA_PLAYER_H
#include "SFML/Graphics.hpp"
#include "AnimatedSprite.h"
#include "MouseEvents.h"
#include "PlayerHealth.h"
#include "Bullet.h"
#include "Hittable.h"

class Player : public sf::Drawable, public Hittable, public States
{
private:
    sf::Clock clock;
    int bulletIndex = 0;
    AnimatedSprite player;
    PlayerHealth healthBar;
    int score = 0;
public:
    std::vector<Bullet>(bullets);
    Player();
    Player(AnimatedSprite& player);
    Player(int row, int col, const sf::Texture& texture, int health, int totalHealth);
    Player(AnimatedSprite& player, int health, int totalHealth);
    void setPosition(const sf::Vector2f& position);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void movePlayerWASD(sf::RenderWindow& window);
    void getHit(int damage) override;
    void heal(int healAmt);
    bool isAlive() const;
    void update();
    void reset();
    sf::Vector2f getPosition() const;
    sf::FloatRect getGlobalBounds() const override;
    int getScore() const;
    void setScore(int score);

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SHOOTA_PLAYER_H
