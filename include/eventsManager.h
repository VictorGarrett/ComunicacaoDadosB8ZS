#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#define GET_CLICKABLE_POINTER(x)  static_cast<Clickable*>(&x)

class Clickable;
class TextInputContainer;

class EventsManager{

    private:
        sf::RenderWindow* window;
        sf::Mouse mouse;
        sf::Event currentEvent;
        std::vector<Clickable*> clickables;
        std::vector<TextInputContainer*> textInputContainers;
        bool windowClosed;
    
    public:
        EventsManager(sf::RenderWindow* pWindow = NULL);
        ~EventsManager();

        void addClickable(Clickable* clkbl);
        void removeClickable(Clickable* clkbl);

        void addTextInputContainer(TextInputContainer* container);
        void removeTextInputContainer(TextInputContainer* container);

        void pollAll();
        void closeWindow();
        bool isWindowClosed();


};
