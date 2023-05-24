#include "program.h"
#include "menu.h"
#include "game.h"

#include <iostream>
#include <stdexcept>

static bool loop()
{
    static int gameResult;
    switch ( menu::execute( gameResult ) )
    {
        case menu::GAME:
            gameResult = game::run();
            return true;
        case menu::QUIT:
            return false;
    }
    throw std::logic_error("Error in menu!");
}

int main ()
try 
{
    program::start();
    while ( loop() );
    program::end();
    return 0;
}
catch (std::exception& e)
{
    std::cerr << "Something went wrong!\n" << e.what() << '\n';
    return 1;
}
