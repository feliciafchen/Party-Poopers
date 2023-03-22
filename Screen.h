//
// Created by Felicia Chen on 12/5/22.
//

#ifndef SHOOTA_SCREEN_H
#define SHOOTA_SCREEN_H
#include "SFML/Graphics.hpp"
#include "ListItem.h"
#include "Fonts.h"

class Screen : public sf::Drawable, public States
{
private:
    sf::Text text, title;
    ListItem button;
public:
    Screen();
    Screen(std::string text, sf::RenderWindow& window);
    void eventHandler(sf::RenderWindow& window, const sf::Event& event);
    void update(sf::RenderWindow& window);
    bool isClick(sf::RenderWindow& window);
protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SHOOTA_SCREEN_H
