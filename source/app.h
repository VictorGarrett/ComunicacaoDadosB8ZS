#pragma once
#include "stdafx.h"

class App {
    private:
        sf::RenderWindow window;

    public:
        App();
        ~App();

        void run ();
};