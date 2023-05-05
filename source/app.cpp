#include "stdafx.h"
#include "app.h"
#include "B8ZS.h"


App::App() {
    this->window.create(sf::VideoMode(1280, 720), "ComDados");
    this->window.setFramerateLimit(60);
    graphicsManager = new GraphicsManager(&window);
    eventsManager = new EventsManager(&window);
}

App::~App() {
    delete graphicsManager;
    delete eventsManager;
}

void App::run() {
    B8ZS b8zs;
    TextButton button;

    
    b8zs.encrypt();
    //button.on_click();
    
    while (this->window.isOpen()){

        eventsManager->pollAll();

        this->window.clear();
        this->window.display();
    }
}

