//
// Created by Felicia Chen on 12/8/22.
//

#ifndef SHOOTA_MOBS_H
#define SHOOTA_MOBS_H
#include "Mob.h"

class Mobs : public sf::Drawable
{
private:
    Mob mob;
    std::vector<Mob>(mobs);
    int killCount;
public:
    Mobs();
    Mobs(sf::Vector2u window);
    void move(sf::Vector2u window, sf::Vector2f player);
    void reset(sf::Vector2u window);
    void attack(Player& player);
    Mob& at(int index);
    int size();
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SHOOTA_MOBS_H
