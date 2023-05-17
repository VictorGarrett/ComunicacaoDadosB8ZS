#pragma once
#include "stdafx.h"


#include "graphicsManager.h"
#include "textButton.h"
#include "eventsManager.h"
#include "B8ZS.h"
#include "graph.h"
#include "textBox.h"
//#include "Vertex.hpp"

class App {
    private:
        sf::RenderWindow window;
        GraphicsManager* graphicsManager;
        EventsManager* eventsManager;

        sf::Font* mainFont;
        
        sf::Text* testText;
        TextButton* button;
        B8ZS* b8zs;
        Graph* testGraph;
        TextBox* testBox;

    public:
        App();
        ~App();

        void update();
        void render();

        void run();
};