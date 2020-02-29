#include <SFML/graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML TEST");

    while (window.isOpen())
    {
        // handle events

        //update game logic

        //draw
        window.clear();

        //draw SFML objects

        window.display();
    }

    return EXIT_SUCCESS;
}