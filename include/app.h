#pragma once
#include "stdafx.h"


#include "graphicsManager.h"
#include "textButton.h"
#include "eventsManager.h"
#include "B8ZS.h"

class App {
    private:
        sf::RenderWindow window;
        GraphicsManager* graphicsManager;
        EventsManager* eventsManager;

        sf::Font* mainFont;

        TextButton* button;
        B8ZS* b8zs;

    public:
        App();
        ~App();

        void update();
        void render();

        void run();
};