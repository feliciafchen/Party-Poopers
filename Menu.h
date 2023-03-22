//
// Created by Felicia Chen on 11/29/22.
//

#ifndef FELICIACHENCS3AFINAL_MENU_H
#define FELICIACHENCS3AFINAL_MENU_H
#include "List.h"
#include "States.h"

#include <iostream>

class Menu : public sf::Drawable, public States
{
private:
    ListItem header;
    List list;
public:
    Menu();
    Menu(std::initializer_list<std::string> items, sf::Vector2f size);
    void addItem(std::string item);
    void setPosition(const sf::Vector2f& position);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void onclick(void (*f)(), sf::RenderWindow& window);
    void update();
    void init();
protected:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};


#endif //FELICIACHENCS3AFINAL_MENU_H
