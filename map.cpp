#include "map.h"
#include "textureManager.h"
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
std::array<std::array<int, 25>, 20> lvl1{
{   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {2,2,2,2,2,2,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}  }
};


Map::Map() : 
water{ TextureManager::loadTexture( "../../assets/water.png" ) },
grass{ TextureManager::loadTexture( "../../assets/grass.png" ) },
dirt{ TextureManager::loadTexture( "../../assets/dirt.png" ) }
{
    loadMap( lvl1 );
    src.x = 0;
    src.y = 0;
    src.w = 32;
    src.h = 32;

    dest.x = 0;
    dest.y = 0;
    dest.w = 32;
    dest.h = 32;
}

Map::~Map()
{
    SDL_DestroyTexture( water );
    SDL_DestroyTexture( grass );
    SDL_DestroyTexture( dirt );
}

void Map::loadMap( std::array<std::array<int, 25>, 20> arr)
{
    for (int row{ 0 }; row < 20; ++row)
    {
        for (int column{ 0 }; column < 25; ++column)
        {
            map[row][column] = arr[row][column];
        }
    }
}

void Map::drawMap()
{
    Type::Terrain type{ Type::water };
    for (int row{ 0 }; row < 20; ++row)
    {
        for (int column{ 0 }; column < 25; ++column)
        {
            type = static_cast<Type::Terrain>(map[row][column]);
            dest.x = column * src.w;
            dest.y = row * src.h;

            switch (type)
            {
                case Type::water:
                    TextureManager::draw( water, src, dest);
                    break;
                case Type::grass:
                    TextureManager::draw( grass, src, dest);
                    break;
                case Type::dirt:
                    TextureManager::draw( dirt, src, dest);
                    break;
                default:
                    break;
            }
        }
    }
}
