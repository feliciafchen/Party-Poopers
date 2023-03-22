//
// Created by Felicia Chen on 11/28/22.
//

#ifndef FELICIACHENCS3AFINAL_ANIMATEDSPRITE_H
#define FELICIACHENCS3AFINAL_ANIMATEDSPRITE_H
#include "Images.h"
#include "States.h"

class AnimatedSprite : public sf::Sprite, public States
{
private:
    sf::Clock clock, deathClock;
    int speed = 100.f, rows, cols;
    sf::Texture texture;
    sf::IntRect intRect;
public:
    AnimatedSprite();
    AnimatedSprite(const sf::Texture& texture);
    AnimatedSprite(int row, int col, const sf::Texture& texture);
    void animateUp();
    void animateDown();
    void animateRight();
    void animateLeft();
    void animateMobDeath();
    void animatePlayerDeath();
    void stillDown();
    int getRows() const;
    int getCols() const;
    const sf::Texture &getTexture1() const;
};


#endif //FELICIACHENCS3AFINAL_ANIMATEDSPRITE_H
