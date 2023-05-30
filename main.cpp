#include "game.h"
Game* game{ nullptr };

int main(int argc, const char* argv[]) 
{

    const int FPS{ 60 };
    const int frameDelay{ 1000 / FPS };

    uint32_t frameStart;
    int frameTime;


    game = new Game();
    game->init("MonsterGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);
    while ( game->running() )
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
    

    return 0;
}
