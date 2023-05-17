#include "eventsManager.h"
#include "clickable.h"
#include "textInputContainer.h"

EventsManager::EventsManager(sf::RenderWindow* pWindow){
    if(pWindow == NULL)
        printf("WARNING: no window set\n");

    window = pWindow;
    windowClosed = false;
}

EventsManager::~EventsManager(){
    
}

void EventsManager::addClickable(Clickable* clkbl){
    if(clkbl){
        clickables.push_back(clkbl);
    }

}

void EventsManager::removeClickable(Clickable* clkbl){
    if(clkbl){
        for(auto i = clickables.begin(); i != clickables.end(); i++)
            if(*i == clkbl){
                clickables.erase(i);
                break;
            }
    }
}

void EventsManager::addTextInputContainer(TextInputContainer* container){
    if(container){
        textInputContainers.push_back(container);
    }
}

void EventsManager::removeTextInputContainer(TextInputContainer* container){
    if(container){
        for(auto i = textInputContainers.begin(); i != textInputContainers.end(); i++)
            if(*i == container){
                textInputContainers.erase(i);
                break;
            }
    }
}

void EventsManager::pollAll(){
    while(window->pollEvent(currentEvent)){
            switch (currentEvent.type){
                case sf::Event::MouseMoved:{
                    auto mousePos = window->mapPixelToCoords(mouse.getPosition(*window));
                    for(auto i = clickables.begin(); i != clickables.end(); i++){
                        if((*i)->clickBox.contains((float)mousePos.x, (float)mousePos.y))
                            (*i)->hovering = true;
                        else{
                            (*i)->hovering = false;
                        }
                    }
                    break;
                }
                case sf::Event::Closed: //Evento da janela fechada
                    windowClosed = true;
                    break;

                case sf::Event::MouseButtonPressed:{ //Caso alguma tecla do mouse seja ativada;
                //printf("mouse button pressed event\n");
                    for(auto i = textInputContainers.begin(); i != textInputContainers.end(); i++)//desseleciona todas as caixas de texto
                        (*i)->setActive(false);
                    auto mousePos = window->mapPixelToCoords(mouse.getPosition(*window));
                    for(auto i = clickables.begin(); i != clickables.end(); i++){//busca pelo clicavel selecionado e clica
                        if((*i)->clickBox.contains(mousePos.x, mousePos.y))
                            (*i)->clicked = true;
                            (*i)->onClicked();
                    }
                    break;
                }
                case sf::Event::MouseButtonReleased: //Caso alguma tecla do mouse seja desativada;
                //printf("mouse button rel event\n");
                    for(auto i = clickables.begin(); i != clickables.end(); i++)//desclica todos os clicaveis
                            (*i)->clicked = false;
                    break;

                case sf::Event::TextEntered:
                    printf("text is entered\n");
                    for(auto i = textInputContainers.begin(); i != textInputContainers.end(); i++){
                            (*i)->addCharacter(currentEvent.text.unicode);
                            (*i)->onTextUpdated();
                    }
                    break;
                
                case sf::Event::KeyPressed:
                    switch(currentEvent.key.code){
                        case sf::Keyboard::Backspace:
                            for(auto i = textInputContainers.begin(); i != textInputContainers.end(); i++){
                                (*i)->eraseCharacter();
                                (*i)->onTextUpdated();
                            }
                            break;
                        case sf::Keyboard::Right:
                            for(auto i = textInputContainers.begin(); i != textInputContainers.end(); i++){
                                (*i)->moveCursor(1);
                                (*i)->onTextUpdated();
                            }
                            break;
                        case sf::Keyboard::Left:
                            for(auto i = textInputContainers.begin(); i != textInputContainers.end(); i++){
                                (*i)->moveCursor(-1);
                                (*i)->onTextUpdated();
                            }
                            break;
                    }

                    break;

                //case sf::Event::Resized:
                    //sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                    
                // window.setView(sf::View(visibleArea));
            // break;
            }
        }
}

void EventsManager::closeWindow(){
    windowClosed = true;
}

bool EventsManager::isWindowClosed(){
    if(windowClosed)
        window->close();

    return windowClosed;
}