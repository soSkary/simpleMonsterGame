#include "game.h"
#include "textureManager.h"
#include "map.h"
#include "ECS/components.h"
#include "vector2D.h"

Map* map;

SDL_Renderer* Game::renderer{ nullptr };
SDL_Event Game::event;
Manager manager;

auto& player{ manager.addEntity() };

Game::Game()
{}
Game::~Game()
{

}
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 )
    {
        std::cout << "Failed to initialize\n" << SDL_GetError() << '\n';
        isRunning = false;
    }
    else
    {
        std::cout << "Subsystems Initialized...\n";

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(!window)
        {
            std::cout << "Failed to create window\n" << SDL_GetError() << '\n';
        }
        else
        {
            std::cout << "Window created\n";
            renderer = SDL_CreateRenderer(window, -1, 0);

            if(!renderer)
            {
                std::cout << "Failed to create renderer\n" << SDL_GetError() << '\n';
            }
            else
            {
                SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
                std::cout << "Renderer created!\n";
            }
        }

        isRunning = true;

    }
    map = new Map();

    player.addComponent<TransformComponent>( 300.0f, 300.0f );
    player.addComponent<SpriteComponent>("../../assets/player.png");
    player.addComponent<KeyboardController>();
}

void Game::handleEvents()
{
    
    SDL_PollEvent( &event );

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;

        default:
            break;
    }
}
void Game::update()
{
    manager.refresh();
    manager.update();
}
void Game::render()
{
    SDL_RenderClear( renderer );
    //To render texture to screen
    map->drawMap();

    manager.draw();
    SDL_RenderPresent( renderer );
}
void Game::clean()
{
    SDL_DestroyWindow( window );
    window = nullptr; 
    SDL_DestroyRenderer( renderer );
    renderer = nullptr;

    SDL_Quit();
    std::cout << "Game cleaned\n";
}
