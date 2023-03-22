#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <cstdlib>
#include "Bullet.h"
#include "Mobs.h"
#include "ListItem.h"
#include "ShootaGame.h"
#include "Screen.h"

int main()
{
    srand(time(nullptr));

    sf::RenderWindow window({2560, 1600, 32}, "party poopers!");
    window.setFramerateLimit(60);

    ListItem back("back", {250, 100});
    back.enableState(HIDDEN);

    ShootaGame shootaGame(window);
    Screen shootaScreen("party poopers!", window);

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            shootaGame.eventHandler(window, event);
            back.eventHandler(window, event);
            shootaScreen.eventHandler(window, event);
        }

        if(!back.checkState(HIDDEN) && back.isClick(window))
        {
            shootaGame.enableState(HIDDEN);
            shootaScreen.disableState(HIDDEN);
            back.enableState(HIDDEN);
        }

        if(shootaScreen.isClick(window))
        {
            shootaGame.disableState(HIDDEN);
            shootaScreen.enableState(HIDDEN);
            back.disableState(HIDDEN);
        }

        window.clear();

        shootaGame.update(window);

        if(!back.checkState(HIDDEN))
        {
            window.draw(back);
        }
        if(!shootaScreen.checkState(HIDDEN))
            window.draw(shootaScreen);

        window.display();
    }

    return 0;
}

//int main()
//{
//    srand(0);
//
//    sf::RenderWindow window({2560, 1600, 32}, "thing");
//    window.setFramerateLimit(60);
//
//    ListItem restart("restart", {500,200});
//    restart.setPosition({window.getSize().x/2 - restart.getGlobalBounds().width/2,
//                        window.getSize().y - restart.getGlobalBounds().height - 50});
//
//    //background
//    sf::Sprite grass(Images::get(GRASS));
//    grass.setScale({1.8,2});
//
//    //player
//    Player player(6.0, 4.0, Images::get(BLOB),100, 100);
//    player.setPosition({window.getSize().x/2 - player.getGlobalBounds().width/2,
//                        window.getSize().y/2 - player.getGlobalBounds().height});
//
//    //mobs
//    Mobs mobs(window.getSize());
//
//    //score
//
//    Score score(std::to_string(player.getScore()));
//
////    std::vector<Screen> screens;
////    for (int i = 0; i < 5; ++i) {
////        screens.emplace_back("Screen " + std::to_string(i+1),
////                             "Button " + std::to_string(i+1));
////    }
////    auto iter = screens.begin();
//
//    while(window.isOpen())
//    {
//        sf::Event event;
//
//        while(window.pollEvent(event))
//        {
//            if(event.type == sf::Event::Closed)
//                window.close();
//            player.eventHandler(window, event);
//            restart.eventHandler(window, event);
////            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
////            {
////                if(iter != screens.begin())
////                    --iter;
////            }
////            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
////            {
////                auto iter2 = iter;
////                if(iter != screens.end() - 1)
////                    ++iter;
////            }
//        }
//
//        if(restart.isClick(window) && !player.isAlive())
//        {
//            restartShoota(player, mobs, score, window.getSize());
//        }
//
//        player.movePlayerWASD(window);
//        mobs.move(window.getSize(), player.getPosition());
//        mobs.attack(player);
//
//        for (int i = 0; i < mobs.size(); ++i) {
//            for (int j = 0; j < 20; ++j) {
//                if(mobs.at(i).isAlive())
//                    player.bullets[j].hit(mobs.at(i));
//            }
//        }
//
//        score.setString("score: " + std::to_string(player.getScore()));
//        window.clear(sf::Color::Black);
//
//        if(player.isAlive())
//        {
//            window.draw(grass);
//            window.draw(player);
//            window.draw(mobs);
//        }
//        else
//        {
//            score.setCharacterSize(60);
//            score.setString("game over! final score: " + std::to_string(player.getScore()));
//            score.setPosition({player.getPosition().x + player.getGlobalBounds().width + 5, player.getPosition().y + player.getGlobalBounds().height/2});
//            window.draw(player);
//            window.draw(restart);
//        }
//        window.draw(score);
////        window.draw(*iter);
//        window.display();
//    }
//
//    return 0;
//}
