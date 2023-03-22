//
// Created by Felicia Chen on 11/28/22.
//
#include "AnimatedSprite.h"

AnimatedSprite::AnimatedSprite() : AnimatedSprite(Images::get(PHASER)){

}

AnimatedSprite::AnimatedSprite(const sf::Texture &texture) : AnimatedSprite(4,12, texture) {

}

AnimatedSprite::AnimatedSprite(int rows, int cols, const sf::Texture &texture)
: rows(rows), cols(cols), texture(texture)
{
    setTexture(texture);
    intRect.width = 1 + texture.getSize().x / cols;
    intRect.height = texture.getSize().y / rows;
    intRect.top = texture.getSize().y / rows * 2.0;
    intRect.left = 0;
    setTextureRect(intRect);
}

void AnimatedSprite::animateUp() {
    intRect.top = (texture.getSize().y / rows * 4.0);
    if(clock.getElapsedTime().asMilliseconds() > speed) {
        if (intRect.left + (2 * intRect.width) > getTexture()->getSize().x) //if exceed texture size, reset to zero
            intRect.left = 0;
        else
            intRect.left += intRect.width - 1; //move box one over to the right = left + its width
        clock.restart();
    }
    setTextureRect(intRect);
}

void AnimatedSprite::animateDown() {
    intRect.top = (texture.getSize().y / rows);
    if(clock.getElapsedTime().asMilliseconds() > speed) {
        if (intRect.left + (2 * intRect.width) > getTexture()->getSize().x) //if exceed texture size, reset to zero
            intRect.left = 0;
        else
            intRect.left += intRect.width - 1; //move box one over to the right = left + its width
        clock.restart();
    }
    setTextureRect(intRect);
}

void AnimatedSprite::animateRight() {
    intRect.top = (texture.getSize().y / rows * 2);
    if(clock.getElapsedTime().asMilliseconds() > speed) {
        if (intRect.left + (2 * intRect.width) > getTexture()->getSize().x) //if exceed texture size, reset to zero
            intRect.left = 0;
        else
            intRect.left += intRect.width - 1; //move box one over to the right = left + its width
        clock.restart();
    }
    setTextureRect(intRect);
}

void AnimatedSprite::animateLeft() {
    intRect.top = (texture.getSize().y / rows * 3);
    if(clock.getElapsedTime().asMilliseconds() > speed) {
        if (intRect.left + (2 * intRect.width) > getTexture()->getSize().x) //if exceed texture size, reset to zero
            intRect.left = 0;
        else
            intRect.left += intRect.width - 1; //move box one over to the right = left + its width
        clock.restart();
    }
    setTextureRect(intRect);
}

void AnimatedSprite::stillDown() {
    intRect.top = (texture.getSize().y / rows);
    intRect.left = 0;
    setTextureRect(intRect);
}

void AnimatedSprite::animateMobDeath() {
    setState(DEAD, true);
    intRect.top = (texture.getSize().y / rows * 2);
    if(deathClock.getElapsedTime().asMilliseconds() > 300) {
        if (intRect.left + (2 * intRect.width) > getTexture()->getSize().x) //if exceed texture size, reset to zero
            intRect.left = 0;
        else
            intRect.left += intRect.width - 1; //move box one over to the right = left + its width
        deathClock.restart();
    }
    setTextureRect(intRect);
}

void AnimatedSprite::animatePlayerDeath() {
    intRect.top = (texture.getSize().y / rows * 5);
    if(clock.getElapsedTime().asMilliseconds() > 300) {
        if (intRect.left + (2 * intRect.width) > getTexture()->getSize().x) //if exceed texture size, reset to zero
            intRect.left = 0;
        else
            intRect.left += intRect.width - 1; //move box one over to the right = left + its width
        clock.restart();
    }
    setTextureRect(intRect);
}

int AnimatedSprite::getRows() const {
    return rows;
}

int AnimatedSprite::getCols() const {
    return cols;
}

const sf::Texture &AnimatedSprite::getTexture1() const {
    return texture;
}


