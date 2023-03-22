//
// Created by Felicia Chen on 11/22/22.
//

#ifndef FELICIACHENCS3AFINAL_MOUSEEVENTS_H
#define FELICIACHENCS3AFINAL_MOUSEEVENTS_H
#include "SFML/Graphics.hpp"

class MouseEvents {
public:
    template<class T>
    static bool isHover(const T& obj, const sf::RenderWindow& window);

    template<class T>
    static bool isClick(const T& obj, const sf::RenderWindow& window);

    template<class T>
    static bool isClick(const T& obj, const sf::RenderWindow& window, const sf::Keyboard::Key button);

    template<class T>
    static bool isNotClick(const T& obj, const sf::RenderWindow& window);
};

#include "MouseEvents.cpp"

#endif //FELICIACHENCS3AFINAL_MOUSEEVENTS_H
