#include <SFML/graphics.hpp>
#include <iostream>

#include "logger.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 700), "Asteroid Field game by Iaroslav Vasiletc");

    while (window.isOpen())
    {
        // handle events

        //update game logic

        //draw
        window.clear();

        //draw SFML objects

        window.display();
        log << "Hello world " << 9;
    }

    return EXIT_SUCCESS;
}