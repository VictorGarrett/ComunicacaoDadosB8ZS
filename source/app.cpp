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

    testGraph = new Graph;

    testGraph->setPosition(sf::Vector2f(400, 400));
    testGraph->setSize(sf::Vector2f(400, 400));
    testGraph->setRange(-50, 50, -50, 50);

    std::vector<sf::Vector2f> testData{{-30, -5},{0, 35},{10, 0},{20, 20}};
    testGraph->setData(testData);

    testText = new sf::Text("caxa de testo ->", *mainFont, 30);
    testText->setPosition(sf::Vector2f(800, 400));

    testBox = new TextBox(mainFont, sf::Vector2f(1100, 400), sf::Vector2f(200, 30));

    eventsManager->addClickable(testBox);
    eventsManager->addTextInputContainer(testBox);

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
    graphicsManager->draw(testGraph);
    graphicsManager->draw(testBox);
    graphicsManager->draw(testText);
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

