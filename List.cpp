//
// Created by Felicia Chen on 11/29/22.
//

#include "List.h"

void List::addItem(const ListItem &item, void (*f)()) {
    items.push_back(item);
}

void List::addItem(const std::string &text, sf::Vector2f size, void (*f)()) {
    ListItem listItem(text, size);
    items.push_back(listItem);
}

void List::setPosition(const sf::Vector2f &position) {
    items[0].setPosition(position);
    for (int i = 1; i < items.size(); ++i) {
        Position::bottom(items[i-1], items[i], 15);
    }
}

void List::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN))
    {
        for (const ListItem& l : items) {
            target.draw(l);
        }
    }
}

void List::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (ListItem& l : items) {
        l.eventHandler(window, event);
    }
}

void List::update() {

}

ListItem &List::atIndex(int index) {
    return items.at(index);
}

sf::FloatRect List::getGlobalBounds() {
    sf::FloatRect f = items[0].getGlobalBounds();
    f.height *= items.size();
    return f;
}
