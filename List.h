//
// Created by Felicia Chen on 11/29/22.
//

#ifndef FELICIACHENCS3AFINAL_LIST_H
#define FELICIACHENCS3AFINAL_LIST_H
#include "List.h"
#include "ListItem.h"
#include "Position.h"
#include <vector>

class List : public sf::Drawable, public States
{
private:
    std::vector<ListItem> items;
public:
    void addItem(const ListItem& item, void (*f)() = nullptr);
    void addItem(const std::string& text, sf::Vector2f size, void (*f)() = nullptr);
    void setPosition(const sf::Vector2f& position);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    ListItem& atIndex(int index);
    sf::FloatRect getGlobalBounds();
};


#endif //FELICIACHENCS3AFINAL_LIST_H
