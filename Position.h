//
// Created by Felicia Chen on 11/22/22.
//

#ifndef FELICIACHENCS3AFINAL_POSITION_H
#define FELICIACHENCS3AFINAL_POSITION_H
#include "SFML/Graphics.hpp"
#include <cmath>

class Position {
public:
    template<class T, class S>
    static void left(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void right(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void center(const T& obj1, S& obj2);

    template<class T, class S>
    static void bottom(const T& obj1, S& obj2, float spacing = 0);

    template<class T, class S>
    static void top(const T& obj1, S& obj2, float spacing = 0);

    template<class T>
    static void centerText(const T &obj, sf::Text &text);
};
#include "Position.cpp"

#endif //FELICIACHENCS3AFINAL_POSITION_H
