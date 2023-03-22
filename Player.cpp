//
// Created by Felicia Chen on 11/30/22.
//

#include "Player.h"

#include <utility>

Player::Player() {
}

Player::Player(AnimatedSprite& player)
        : Player(player.getRows(), player.getCols(), player.getTexture1(), 50, 50)
{
}

Player::Player(AnimatedSprite &player, int health, int totalHealth)
        : Player(player.getRows(), player.getCols(), player.getTexture1(), 50, 50)
{
}

Player::Player(int row, int col, const sf::Texture& texture, int health, int totalHealth)
{
    AnimatedSprite player(row, col, texture);
    PlayerHealth healthBar(health, totalHealth, player);
    this -> player = player;
    this -> healthBar = healthBar;
    this -> player.setScale(10, 10);
    this -> healthBar.setScale({10,10});
    this -> healthBar.setPosition({player.getPosition().x, player.getPosition().y + player.getGlobalBounds().height + 240});

    Bullet bullet;
    for (int i = 0; i < 20; ++i) {
        bullets.push_back(bullet);
        bullets[i].enableState(HIDDEN);
    }
    bulletIndex = 0;
}

void Player::setPosition(const sf::Vector2f &position) {
    player.setPosition(position);
    Position::bottom(player, healthBar, 10);
}

void Player::eventHandler(sf::RenderWindow &window, sf::Event event) {
}

void Player::update() {

}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < bullets.size(); ++i) {
        if(!bullets[i].checkState(HIDDEN))
            target.draw(bullets.at(i));
    }
    target.draw(player);
    target.draw(healthBar);
}

void Player::movePlayerWASD(sf::RenderWindow &window) {
    if(isAlive())
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && clock.getElapsedTime().asMilliseconds() > 200)
        {
            bulletIndex++;
            bulletIndex = bulletIndex%20;
            bullets[bulletIndex].disableState(HIDDEN);
            bullets[bulletIndex].setPosition({player.getPosition().x + player.getGlobalBounds().width/2 - bullets[0].getGlobalBounds().width/2,
                                  player.getPosition().y + player.getGlobalBounds().height/2});
            sf::Vector2f direction = {(sf::Mouse::getPosition(window).x - bullets[bulletIndex].getPosition().x),
                                      (sf::Mouse::getPosition(window).y - bullets[bulletIndex].getPosition().y)};
            bullets[bulletIndex].setVelocity({direction.x * 0.05f,direction.y * 0.05f});
            clock.restart();
        }

        sf::Vector2f position = player.getPosition();
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && player.getPosition().y + player.getGlobalBounds().height < window.getSize().y)
        {
            player.animateDown();
            player.move({0, 10});
            healthBar.move({0, 10});
        }
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::W)) && player.getPosition().y > -50)
        {
            player.animateUp();
            player.move({0, -10});
            healthBar.move({0, -10});
        }
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && player.getPosition().x > -25)
        {
            player.animateLeft();
            player.move({-10, 0});
            healthBar.move({-10, 0});
        }
        if((sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && player.getPosition().x + player.getGlobalBounds().width - 25< window.getSize().x)
        {
            player.animateRight();
            player.move({10, 0});
            healthBar.move({10, 0});
        }

        if(position == player.getPosition())
        {
            player.stillDown();
        }
    }
    else
    {
        player.animatePlayerDeath();
    }

    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i].move();
    }
}

void Player::getHit(int damage) {
    healthBar.hit(damage);
}

void Player::heal(int healAmt) {
    healthBar.heal(healAmt);
}


sf::Vector2f Player::getPosition() const {
    return player.getPosition();
}

bool Player::isAlive() const{
    return healthBar.isAlive();
}

sf::FloatRect Player::getGlobalBounds() const {
    return player.getGlobalBounds();
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}

void Player::reset() {
    score = 0;
    clock.restart();
    healthBar.makeFullHealth();
}
