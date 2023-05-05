#include "stdafx.h"
#include "app.h"



App::App() {
    this->window.create(sf::VideoMode(1280, 720), "ComDados");
    this->window.setFramerateLimit(60);
    graphicsManager = new GraphicsManager(&window);
    eventsManager = new EventsManager(&window);

    mainFont = graphicsManager->loadFont("assets/Pixel.ttf");

    b8zs = new B8ZS();

    button = new TextButton(mainFont, "kkbotao", 50, sf::Color::White, {300.0f, 300.0f});
    eventsManager->addClickable(button);
}

App::~App() {
    delete graphicsManager;
    delete eventsManager;
    delete b8zs;

    eventsManager->removeClickable(button);
    delete button;
}

void App::update(){
    eventsManager->pollAll();

    if(button->isHovering()){
        button->setFillColor(sf::Color::Red);
    }
    else
        button->setFillColor(sf::Color::White);

    if(button->wasClicked())
        printf("kk clico no kkbotao\n");
}

void App::render(){
    graphicsManager->draw(button);
    graphicsManager->render();
}

void App::run() {
   

    
    b8zs->encrypt();
    //button.on_click();
    
    while (!eventsManager->isWindowClosed()){
        update();
        render();
    }
}

