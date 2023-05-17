#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "clickable.h"
#include "textInputContainer.h"

class TextBox: public Clickable, public TextInputContainer, public sf::Drawable{

public:

    TextBox(sf::Font* font = NULL, sf::Vector2f position = {0.0f, 0.0f}, sf::Vector2f size = {0.0f, 0.0f});
    ~TextBox();

    virtual void onTextUpdated() override;

    virtual void onClicked() override;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    //set top left position
    void setPosition(sf::Vector2f pos);

    //set boundary size
    void setSize(sf::Vector2f size);

    void setLoadedFont(sf::Font* font);

private:

    sf::Font* font;
    sf::RectangleShape boundary;
    sf::Text displayText;
    sf::VertexArray cursorBar;

    void fitCursorBar();
    void fitText();

};
