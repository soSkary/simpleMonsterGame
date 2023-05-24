#include "menu.h"
#include "program.h"
#include <iostream>

menu::selection menu::execute(int gameResult)
{
    std::clog <<  "menu::execute(" << gameResult << ")\n";
    static bool gameOver{ false };
    if (!gameOver)
    {
        gameOver = true;
        std::clog << ">> GAME\n";
        return menu::GAME;
    }
    std::clog << ">> OVER\n";
    return menu::QUIT;
}
