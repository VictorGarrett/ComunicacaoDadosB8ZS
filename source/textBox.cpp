#include "textBox.h"

TextBox::TextBox(sf::Font* font, sf::Vector2f position, sf::Vector2f size): boundary(size), displayText(std::string(""), *font, 30), cursorBar(sf::PrimitiveType::LineStrip, 2){
    printf("new text box\n");
    if(!font)
        printf("WARNING: no font set!\n");

    this->font = font;
    setPosition(position);
    setClickBox(boundary.getGlobalBounds());
    boundary.setFillColor(sf::Color::Black);
    boundary.setOutlineColor(sf::Color::White);
    boundary.setOutlineThickness(2);
    //setFillColor(color);

    displayText.setFillColor(sf::Color::White);
}

TextBox::~TextBox(){

}

void TextBox::onTextUpdated(){
    displayText.setString(text);
    fitText();
    fitCursorBar();
}

void TextBox::onClicked(){
    active = true;
    printf("clicked active true\n");
    printf(text.c_str());
}

void TextBox::draw(sf::RenderTarget& target, sf::RenderStates states) const{  
    target.draw(boundary, states);
    target.draw(displayText, states);

    if(active)
        target.draw(cursorBar, states);
}
//set top left position
void TextBox::setPosition(sf::Vector2f pos){
    boundary.setPosition(pos);
    fitText();
    fitCursorBar();
}

//set boundary size
void TextBox::setSize(sf::Vector2f size){
    boundary.setSize(size);
    fitText();
    fitCursorBar();
}

void TextBox::setLoadedFont(sf::Font* font){
    this->font = font;
    displayText.setFont(*font);
    fitText();
    fitCursorBar();
}

void TextBox::fitCursorBar(){
    sf::Vector2f pos = displayText.findCharacterPos(cursorPosition);

    cursorBar[0] = pos;
    cursorBar[1] = pos + sf::Vector2f(0, displayText.getGlobalBounds().height);
}

void TextBox::fitText(){
    if(!text.size())
        return;

    float scaleFactor = (0.65*boundary.getGlobalBounds().height)/displayText.getGlobalBounds().height;
    sf::Vector2f pos(boundary.getGlobalBounds().left + 0.05*boundary.getGlobalBounds().height, boundary.getGlobalBounds().top + 0.05*boundary.getGlobalBounds().height);

    displayText.scale(scaleFactor, scaleFactor);

    displayText.setPosition(pos);

    printf("text fitted  %f, %f, %f, %f\n", displayText.getGlobalBounds().left, displayText.getGlobalBounds().top, displayText.getGlobalBounds().width, displayText.getGlobalBounds().height);
}
