//
// Created by Felicia Chen on 12/5/22.
//

#include "Screen.h"

Screen::Screen()
{
}

Screen::Screen(std::string text, sf::RenderWindow& window)
        : text(text, Fonts::getFont(RAINY_HEARTS), 200)
{
    title.setFont(Fonts::getFont(RAINY_HEARTS));
    title.setCharacterSize(125);
    title.setFillColor(sf::Color::White);
    title.setPosition({window.getSize().x/2 - title.getGlobalBounds().width/2,
                       100});

    ListItem restart("start", {500,200});
    restart.setPosition({window.getSize().x/2 - restart.getGlobalBounds().width/2,
                         window.getSize().y - restart.getGlobalBounds().height - 50});
    this -> button = restart;

    sf::RectangleShape windowbox({2560, 1600});
    Position::centerText(windowbox, this->text);
}

void Screen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(title);
    target.draw(text);
    target.draw(button);
}

void Screen::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    button.eventHandler(window, event);
}

void Screen::update(sf::RenderWindow& window) {
    window.draw(title);
    window.draw(text);
    window.draw(button);
}

bool Screen::isClick(sf::RenderWindow &window) {
    if(MouseEvents::isClick(button, window))
    {
        return true;
    }
}
