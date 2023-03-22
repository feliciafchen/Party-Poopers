//
// Created by Felicia Chen on 12/14/22.
//

#include "ShootaGame.h"

ShootaGame::ShootaGame(sf::RenderWindow& window) {

    ListItem restart("restart", {500,200});
    restart.setPosition({window.getSize().x/2 - restart.getGlobalBounds().width/2,
                         window.getSize().y - restart.getGlobalBounds().height - 50});
    this -> restart = restart;

    //background
    sf::Sprite grass(Images::get(GRASS));
    grass.setScale({1.8,2});
    this -> grass = grass;

    //player
    Player player(6.0, 4.0, Images::get(BLOB),100, 100);
    player.setPosition({window.getSize().x/2 - player.getGlobalBounds().width/2,
                        window.getSize().y/2 - player.getGlobalBounds().height});
    this -> player = player;

    //mobs
    Mobs mobs(window.getSize());
    this -> mobs = mobs;

    //score
    this -> score.setFont(Fonts::getFont(RAINY_HEARTS));
    this -> score.setString("score: " + std::to_string(player.getScore()));
    this -> score.setCharacterSize(150);
    this -> score.setFillColor(sf::Color::White);
    this -> score.setPosition({50, 1350});

    enableState(HIDDEN);
}

void ShootaGame::eventHandler(sf::RenderWindow &window, sf::Event event) {
    player.eventHandler(window, event);
    restart.eventHandler(window, event);
}

void ShootaGame::update(sf::RenderWindow& window) {
    if(!checkState(HIDDEN))
    {
        if(restart.isClick(window) && !player.isAlive())
        {
            restartShoota(window.getSize());
        }

        player.movePlayerWASD(window);
        mobs.move(window.getSize(), player.getPosition());
        mobs.attack(player);

        for (int i = 0; i < mobs.size(); ++i) {
            for (int j = 0; j < 20; ++j) {
                if(mobs.at(i).isAlive())
                    player.bullets[j].hit(mobs.at(i));
            }
        }

        score.setString("score: " + std::to_string(player.getScore()));
        window.clear(sf::Color::Black);

        if(player.isAlive())
        {
            window.draw(grass);
            window.draw(player);
            window.draw(mobs);
        }
        else
        {
            score.setCharacterSize(60);
            score.setString("game over! final score: " + std::to_string(player.getScore()));
            score.setPosition({player.getPosition().x + player.getGlobalBounds().width + 5, player.getPosition().y + player.getGlobalBounds().height/2});
            window.draw(player);
            window.draw(restart);
        }
        window.draw(score);
    }
}

void ShootaGame::restartShoota(sf::Vector2u window) {
    player.setPosition({window.x/2 - player.getGlobalBounds().width/2,
                        window.y/2 - player.getGlobalBounds().height});
    player.reset();
    mobs.reset(window);
    score.setCharacterSize(150);
    score.setString("score: " + std::to_string(player.getScore()));
    score.setFillColor(sf::Color::White);
    score.setPosition({50, 1350});
}