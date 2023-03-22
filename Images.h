//
// Created by Felicia Chen on 11/28/22.
//

#ifndef FELICIACHENCS3AFINAL_IMAGES_H
#define FELICIACHENCS3AFINAL_IMAGES_H
#include "SFML/Graphics.hpp"
#include <map>
#include "imageEnum.h"

class Images {
private:
    static std::map<imageEnum, sf::Texture> images;
    static void load(imageEnum image);
    static std::string getPath(imageEnum image);
public:
    static sf::Texture& get(imageEnum image);
};


#endif //FELICIACHENCS3AFINAL_IMAGES_H
