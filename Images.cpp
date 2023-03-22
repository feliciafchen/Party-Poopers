//
// Created by Felicia Chen on 11/28/22.
//

#include "Images.h"
std::map<imageEnum, sf::Texture> Images::images;

void Images::load(imageEnum image) {
    if(!images[image].loadFromFile(getPath(image)))
        exit(65);
}

std::string Images::getPath(imageEnum image) {
    switch(image)
    {
        case PHASER:
            return "images/phaser.png";
        case BLOB:
            return "images/BLOBPLAYER.png";
        case GRASS:
            return "images/pixelgrass.png";
        case MOB:
            return "images/MOB.png";
        case LAST_IMAGE:
            break;
    }
}

sf::Texture &Images::get(imageEnum image) {
    load(image);
    return images.at(image);
}
