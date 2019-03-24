#include <iostream>
#include "Game.hpp"

int main()
{
    // int style = sf::Style::Fullscreen;
    // Create the main window
    // sf::VideoMode::getFullscreenModes().front()
    Game pacWoman;
    pacWoman.run();

    return EXIT_SUCCESS;
}
