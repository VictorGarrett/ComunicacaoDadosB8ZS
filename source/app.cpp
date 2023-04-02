#include "stdafx.h"
#include "app.h"
#include "core/B8ZS.h"
#include "render/button.h"

App::App() {
    this->window.create(sf::VideoMode(1280, 720), "ComDados");
    this->window.setFramerateLimit(60);
}

App::~App() { }

void App::run() {
    B8ZS b8zs;
    Button button;

    
    b8zs.encrypt();
    button.on_click();
    
    while (this->window.isOpen())
    {
        sf::Event event;
        while (this->window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window.close();
        }

        this->window.clear();
        this->window.display();
    }
}

