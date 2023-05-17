#pragma once

#include <SFML/Graphics.hpp>

class Clickable{
    protected:
        sf::FloatRect clickBox;
        bool hovering;
        bool clicked;

    public:
        Clickable(sf::FloatRect clickBox = {0.0f, 0.0f, 0.0f, 0.0f});
        ~Clickable();

        bool isHovering();
        bool wasClicked();
        void setClickBox(sf::FloatRect clickBox);
        virtual void onClicked() {};
        //void hover();
        //void clear();

        friend class EventsManager;

};