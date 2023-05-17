#include "textInputContainer.h"

TextInputContainer::TextInputContainer(){
    cursorPosition = 0;
}

TextInputContainer::~TextInputContainer(){

}

void TextInputContainer::addCharacter(int character){
    if(!active)
        return;

    printf("cahris %d\n", character);
    if(character == 8)//backspace is trouble
        return;

    std::string newText;
    if(cursorPosition == text.size()){
        newText = text + (char)character;
    }
    else{
        

        for(int i = 0; i < cursorPosition; i++)
            newText += text[i];

        newText += (char)character;

        for(int i = cursorPosition; i < text.size(); i++)
            newText += text[i];
    }

    if(newText.size() > text.size()){
        text = newText;
        cursorPosition++;
    }
}

std::string TextInputContainer::getText() const{
    return text;
}

void TextInputContainer::clear(){
    text.clear();
}

void TextInputContainer::setActive(bool active){
    this->active = active;
}

bool TextInputContainer::getActive() const{
    return active;
}

void TextInputContainer::moveCursor(int amount){
    cursorPosition += amount;
    if(cursorPosition < 0)
        cursorPosition = 0;
    else if(cursorPosition > text.size())
        cursorPosition = text.size();
}

void TextInputContainer::eraseCharacter(){
    if(!text.size())
        return;
    printf("erasing %d of %s, ", cursorPosition, text.c_str());
    text.erase(cursorPosition-1);
    cursorPosition--;
    printf("%s, %d\n", text.c_str(), cursorPosition);
}