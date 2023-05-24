#ifndef _MENU_H
#define _MENU_H

namespace menu 
{
    enum selection 
    {
        QUIT, GAME
    };

// Main menu function; needs game result, returns the selection.
selection execute(int gameResult);
}

#endif
