//
// Created by Felicia Chen on 11/22/22.
//

#ifndef FELICIACHENCS3AFINAL_FONTS_H
#define FELICIACHENCS3AFINAL_FONTS_H
#include "SFML/Graphics.hpp"
#include "fontsEnum.h"

class Fonts
{
private:
    static std::map<fontsEnum, sf::Font> map;
    static void load(fontsEnum font);
    static std::string getPath(fontsEnum font);
public:
    static sf::Font& getFont(fontsEnum font);
};


#endif //FELICIACHENCS3AFINAL_FONTS_H
