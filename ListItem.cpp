//
// Created by Felicia Chen on 11/29/22.
//

#include "ListItem.h"

ListItem::ListItem() : ListItem("", {0.f, 0.f}){

}

ListItem::ListItem(std::string text, sf::Vector2f size) {
    setupBox(size);
    setupText(text);
}

void ListItem::onclick(void (*f)(), sf::RenderWindow& window) {
    if(MouseEvents::isClick(box, window))
    {
        f();
    }
}

void ListItem::eventHandler(sf::RenderWindow &window, const sf::Event &event) {
    if(MouseEvents::isHover(box, window))
    {
        box.setFillColor(hoverColor);
        text.setFillColor(sf::Color::Black);
    }
    else
    {
        box.setFillColor(backgroundColor);
        text.setFillColor(hoverColor);
    }
}

void ListItem::update() {

}

void ListItem::setupText(std::string text) {
    this -> text.setFont(Fonts::getFont(RAINY_HEARTS));
    this -> text.setString(text);
    this -> text.setCharacterSize(100);
    this -> text.setFillColor(sf::Color::White);
    Position::centerText(box, this->text);
}

void ListItem::setupBox(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, text);
}

void ListItem::setBoxSize(sf::Vector2f size) {
    box.setSize(size);
    Position::centerText(box, text);
}

void ListItem::setTextSize(unsigned int size) {
    text.setCharacterSize(size);
    Position::centerText(box, text);
}

void ListItem::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!checkState(HIDDEN))
    {
        target.draw(box);
        target.draw(text);
    }
}

void ListItem::setPosition(const sf::Vector2f& position) {
    box.setPosition({position});
    Position::centerText(box, text);
}

sf::FloatRect ListItem::getGlobalBounds() const {
    return box.getGlobalBounds();
}

sf::RectangleShape ListItem::getBox() const {
    return box;
}

void ListItem::setString(std::string text) {
    this -> text.setString(text);
}

void ListItem::setPosition(float x, float y) {
    setPosition({x, y});
}

bool ListItem::isClick(sf::RenderWindow& window) {
    if(MouseEvents::isClick(box, window))
    {
        return true;
    }
}

void ListItem::setBox(const sf::RectangleShape &box) {
    ListItem::box = box;
}

const sf::Text &ListItem::getText() const {
    return text;
}

void ListItem::setText(const sf::Text &text) {
    ListItem::text = text;
}

const sf::Color &ListItem::getBackgroundColor() const {
    return backgroundColor;
}

void ListItem::setBackgroundColor(const sf::Color &backgroundColor) {
    ListItem::backgroundColor = backgroundColor;
}

const sf::Color &ListItem::getHoverColor() const {
    return hoverColor;
}

void ListItem::setHoverColor(const sf::Color &hoverColor) {
    ListItem::hoverColor = hoverColor;
}
