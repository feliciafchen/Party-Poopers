//
// Created by Felicia Chen on 11/29/22.
//

#include "Menu.h"

Menu::Menu() {
}

Menu::Menu(std::initializer_list<std::string> items, sf::Vector2f size)
{
    std::initializer_list<std::string>::iterator iter = items.begin();
    header.setString(*iter);
    header.setBoxSize(size);
    ++iter;
    for (; iter != items.end(); ++iter) {
        list.addItem(*iter, size);
    }
    init();
}

void Menu::addItem(std::string item) {
    list.addItem(item, header.getBox().getSize());
}

void Menu::setPosition(const sf::Vector2f &position) {
    header.setPosition(position);
    Position::bottom(header, list, 15);
}

void Menu::eventHandler(sf::RenderWindow &window, sf::Event event) {
    list.eventHandler(window, event);
    header.eventHandler(window, event);
    if(MouseEvents::isClick(header, window))
    {
        list.disableState(HIDDEN);
    }
    else if(MouseEvents::isNotClick(header, window))
    {
        list.enableState(HIDDEN);
    }
}

void Menu::onclick(void (*f)(), sf::RenderWindow &window) {

}

void Menu::update() {

}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(header);
    target.draw(list);
}

void Menu::init() {
    list.enableState(HIDDEN);
    setPosition({0,0});
}
