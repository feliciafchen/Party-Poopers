//
// Created by Felicia Chen on 11/22/22.
//

#ifndef FELICIACHENCS3AFINAL_MOUSEEVENTS_CPP
#define FELICIACHENCS3AFINAL_MOUSEEVENTS_CPP
#include "MouseEvents.h"

template<class T>
bool MouseEvents::isHover(const T &obj, const sf::RenderWindow &window) {
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return obj.getGlobalBounds().contains(mpos);
}

template<class T>
bool MouseEvents::isClick(const T &obj, const sf::RenderWindow &window) {
    return isHover(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents::isClick(const T &obj, const sf::RenderWindow &window, const sf::Keyboard::Key button) {
    return sf::Keyboard::isKeyPressed(button);
}

template<class T>
bool MouseEvents::isNotClick(const T &obj, const sf::RenderWindow &window) {
    return !isHover(obj, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);;
}

#endif
