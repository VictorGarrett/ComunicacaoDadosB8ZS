#pragma once
#include "stdafx.h"

#include "graphicsManager.h"
#include "textButton.h"
#include "eventsManager.h"

class App {
    private:
        sf::RenderWindow window;
        GraphicsManager* graphicsManager;
        EventsManager* eventsManager;

    public:
        App();
        ~App();

        void run ();
};