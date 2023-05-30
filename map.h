#ifndef MAP_H
#define MAP_H

#include "game.h"
#include <array>

class Map
{
public:
    Map();
    ~Map();

    void loadMap( std::array<std::array<int, 25>, 20> arr );
    void drawMap();

private:
    SDL_Rect src;
    SDL_Rect dest;

    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

    std::array<std::array<int, 25>, 20> map;
};




#endif
