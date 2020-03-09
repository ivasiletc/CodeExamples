#include <SFML/graphics.hpp>
#include <iostream>

#include "logger.h"
#include "Game.hpp"
#include "DEFINITIONS.hpp"

int main()
{
    Game(SCREEN_WIDTH, SCREEN_HEIGHT, "Asteroid Game by Iaroslav Vasiletc");

    return EXIT_SUCCESS;
}