#include "map.h"
#include "game.h"
#include <cstdlib>
#include <fstream>

namespace Type
{
    enum Terrain
    {
        water,
        grass,
        dirt,

        max_types
    };
}



Map::Map() 
{

}

Map::~Map()
{
    
}

void Map::loadMap( std::string path, int sizeX, int sizeY)
{
    char tile;
    std::fstream mapFile(path, std::ios::in);

    for (int y{ 0 }; y < sizeY; ++y)
    {
        for (int x{ 0 }; x < sizeX; ++x)
        {
            mapFile.get(tile);
            Game::addTile(std::atoi(&tile), x * 32, y * 32);
            mapFile.ignore();
        }
    }

    mapFile.close();
}


