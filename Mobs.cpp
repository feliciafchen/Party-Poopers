//
// Created by Felicia Chen on 12/8/22.
//

#include "Mobs.h"

Mobs::Mobs(sf::Vector2u window) {
    Mob mob(3.0, 4.0, Images::get(MOB));
    mob.setState(HIDDEN, false);
    mob.setState(DEAD, false);
    this -> mob = mob;
    for (int i = 0; i < 15; ++i) {
        mobs.push_back(mob);
        mobs[i].setRandomPosition(window);
    }
}

void Mobs::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < mobs.size(); ++i) {
        target.draw(mobs[i]);
    }
}

void Mobs::move(sf::Vector2u window, sf::Vector2f player) {
    for (int i = 0; i < mobs.size(); ++i) {
        if(mobs[i].checkState(DEAD) && mobs[i].checkState(HIDDEN))
        {
            mobs[i].setState(DEAD, false);
            mobs[i] = mob;
            mobs[i].setState(HIDDEN, true);
            mobs[i].deathClock.restart();
        }

        if(!(mobs[i].checkState(DEAD)) && (mobs[i].deathClock.getElapsedTime().asMilliseconds() > 2000)
        && (mobs[i].checkState(HIDDEN)))
        {
            mobs[i].setFullHealth();
            mobs[i].setRandomPosition(window);
            mobs[i].setState(HIDDEN, false);
            mobs[i].setState(DEAD, false);
        }

        if(!mobs[i].checkState(HIDDEN))
            mobs[i].move(player);
    }
}

void Mobs::attack(Player &player) {
    for (int i = 0; i < mobs.size(); ++i) {
        mobs[i].attack(player);
    }
}

Mob &Mobs::at(int index) {
    return mobs[index];
}

int Mobs::size() {
    return mobs.size();
}

void Mobs::reset(sf::Vector2u window) {
    for (int i = 0; i < mobs.size(); ++i) {
        mobs[i].setFullHealth();
        mobs[i].setState(HIDDEN, false);
        mobs[i].setState(DEAD, false);
        mobs[i].setRandomPosition(window);
    }
}

Mobs::Mobs() : Mobs({2560, 1600}){

}
