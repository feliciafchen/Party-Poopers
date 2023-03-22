//
// Created by Felicia Chen on 12/7/22.
//

#ifndef SHOOTA_HITTABLE_H
#define SHOOTA_HITTABLE_H

class Hittable {
public:
    virtual void getHit(int damage) = 0;
    virtual sf::FloatRect getGlobalBounds() const = 0;
};

#endif //SHOOTA_HITTABLE_H
