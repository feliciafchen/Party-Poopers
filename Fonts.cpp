//
// Created by Felicia Chen on 11/22/22.
//

#include "Fonts.h"

std::map<fontsEnum, sf::Font> Fonts::map;
void Fonts::load(fontsEnum font) {
    map[font].loadFromFile(getPath(font));
}

std::string Fonts::getPath(fontsEnum font) {
    switch (font) {
        case SNOWY_WINTER: return "fonts/SnowyWinter.otf";
        case ROBOTO: return "fonts/Roboto-Medium copy.ttf";
        case RAINY_HEARTS: return "fonts/rainyhearts.ttf";
        case LAST_FONT:
            break;
    }
}

sf::Font &Fonts::getFont(fontsEnum font) {
    load(font);
    return map.at(font);
}
