//
// Created by Felicia Chen on 12/5/22.
//

#include "Mob.h"

Mob::Mob() {
}

Mob::Mob(AnimatedSprite &mob)
: Mob(mob, 100, 100)
{
}

Mob::Mob(AnimatedSprite &mob, int health, int totalHealth) {
    PlayerHealth healthBar(health, totalHealth, mob);
    this -> mob = mob;
    this -> mob.setScale(8,8);
    this -> healthBar = healthBar;
    this -> healthBar.setScale({8, 8});
    this -> healthBar.setPosition({mob.getPosition().x, mob.getPosition().y + mob.getGlobalBounds().height + 240});
}

Mob::Mob(int row, int col, const sf::Texture& texture)
{
    AnimatedSprite mob(row, col, texture);
    PlayerHealth healthBar(100, 100, mob);
    this -> mob = mob;
    this -> mob.setScale(8,8);
    this -> healthBar = healthBar;
    this -> healthBar.setScale({8, 8});
    this -> healthBar.setPosition({mob.getPosition().x, mob.getPosition().y + mob.getGlobalBounds().height + 240});
    setState(HIDDEN, false);
}

Mob::Mob(int row, int col, const sf::Texture& texture, int health, int totalHealth)
{
    AnimatedSprite mob(row, col, texture);
    PlayerHealth healthBar(health, totalHealth, mob);
    this -> mob = mob;
    this -> mob.setScale(8,8);
    this -> healthBar = healthBar;
    this -> healthBar.setScale({8, 8});
    this -> healthBar.setPosition({mob.getPosition().x, mob.getPosition().y + mob.getGlobalBounds().height + 240});
    setState(HIDDEN, false);
}


void Mob::move(sf::Vector2f player) {
    if(isAlive())
    {
        mob.animateDown();
        sf::Vector2f direction = {(player.x - mob.getPosition().x),(player.y - mob.getPosition().y)};
        mob.setPosition({mob.getPosition().x + static_cast<float>(0.001 * direction.x),
                         mob.getPosition().y + static_cast<float>(0.001 * direction.y)});
        healthBar.setPosition({mob.getPosition().x + static_cast<float>(0.005 * direction.x),
                               mob.getPosition().y + static_cast<float>(0.005 * direction.y) + 200});
    }
    else
    {
        mob.animateMobDeath();
    }
}

void Mob::setPosition(const sf::Vector2f &position) {
    mob.setPosition(position);
    this -> healthBar.setPosition({mob.getPosition().x, mob.getPosition().y + mob.getGlobalBounds().height + 240});
}

void Mob::eventHandler(sf::RenderWindow &window, sf::Event event) {

}

void Mob::update() {

}

void Mob::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!mob.checkState(HIDDEN))
    {
        target.draw(mob);
        if(!checkState(DEAD))
            target.draw(healthBar);
    }
}

void Mob::attack(Player &player) {
    sf::FloatRect b = player.getGlobalBounds();
    b.width -= 15;
    b.height -= 20;
    b.top += 20;
    b.left += 15;
    if(!checkState(DEAD) && !checkState(HIDDEN) && b.intersects(mob.getGlobalBounds()) && clock.getElapsedTime().asMilliseconds() > 650)
    {
        player.getHit(10);
        clock.restart();
    }
    if(checkState(DEAD) && b.intersects(mob.getGlobalBounds()) && clock.getElapsedTime().asMilliseconds() > 650)
    {
        if(!checkState(HIDDEN))
            player.setScore(player.getScore() + 1);
        setState(HIDDEN,true);
    }

}

void Mob::getHit(int damage) {
    healthBar.hit(damage);
}

sf::FloatRect Mob::getGlobalBounds() const {
    return mob.getGlobalBounds();
}

bool Mob::isAlive() const {
    return healthBar.isAlive();
}


void Mob::still() {
    mob.move({0,0});
}

sf::Vector2f Mob::getPosition() {
    return mob.getPosition();
}

void Mob::setState(statesEnum state, bool condition) {
    mob.setState(state, condition);
}

bool Mob::checkState(statesEnum state) const {
    return mob.checkState(state);
}

void Mob::setFullHealth() {
    healthBar.makeFullHealth();
}

const sf::Vector2f &Mob::getSpawnPoint() const {
    return spawnPoint;
}

void Mob::setSpawnPoint(const sf::Vector2f &spawnPoint) {
    Mob::spawnPoint = spawnPoint;
}

void Mob::setRandomPosition(sf::Vector2u window) {
    int p = rand() % 4;
    float x = rand() % window.x;
    float y = rand() % window.y;
    if(p == 0)
    {
        setPosition({x, 0 - getGlobalBounds().height - 10});
    }
    else if(p == 1)
    {
        setPosition({x, window.y + getGlobalBounds().height + 10});
    }
    else if(p == 2)
    {
        setPosition({0 - getGlobalBounds().width - 10, y});
    }
    else if(p == 3)
    {
        setPosition({window.x + getGlobalBounds().width + 10, y});
    }
}
