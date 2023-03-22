//
// Created by Felicia Chen on 11/29/22.
//

#ifndef FELICIACHENCS3AFINAL_LISTITEM_H
#define FELICIACHENCS3AFINAL_LISTITEM_H
#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Fonts.h"
#include "MouseEvents.h"
#include "States.h"


class ListItem : public sf::Drawable, public States
{
private:
    sf::RectangleShape box;
    sf::Text text;
    void setupText(std::string text);
    void setupBox(sf::Vector2f size);
    sf::Color backgroundColor = sf::Color::Transparent;
    sf::Color hoverColor = sf::Color::White;

protected:
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    ListItem();
    ListItem(std::string text, sf::Vector2f size);
    void setPosition(const sf::Vector2f& position);
    void setPosition(float x, float y);
    sf::FloatRect getGlobalBounds() const;
    sf::RectangleShape getBox() const;
    void onclick(void (*f)(), sf::RenderWindow& window);
    bool isClick(sf::RenderWindow& window);
    void eventHandler(sf::RenderWindow& window, const sf::Event& event);
    void update();
    void setBoxSize(sf::Vector2f size);
    void setTextSize(unsigned int size);
    void setString(std::string text);
    void setBox(const sf::RectangleShape &box);
    const sf::Text &getText() const;
    void setText(const sf::Text &text);
    const sf::Color &getBackgroundColor() const;
    void setBackgroundColor(const sf::Color &backgroundColor);
    const sf::Color &getHoverColor() const;
    void setHoverColor(const sf::Color &hoverColor);
};


#endif //FELICIACHENCS3AFINAL_LISTITEM_H
