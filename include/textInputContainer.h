#pragma once

#include <string>

class TextInputContainer{

public:
    TextInputContainer();
    ~TextInputContainer();

    virtual void onTextUpdated() = 0;

    void addCharacter(int character);
    std::string getText() const;
    void clear();
    void setActive(bool active);
    bool getActive() const;
    void moveCursor(int amount);
    void eraseCharacter();

protected:
    std::string text;
    bool active;
    int cursorPosition;
};