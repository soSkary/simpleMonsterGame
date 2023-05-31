#include "collision.h"
#include "game.h"
#include "textureManager.h"
#include "map.h"
#include "ECS/components.h"
#include "vector2D.h"

Map* map;
Manager manager;

SDL_Renderer* Game::renderer{ nullptr };
SDL_Event Game::event;

std::vector<ColliderComponent *> Game::colliders;

auto& player{ manager.addEntity() };
//auto& wall{ manager.addEntity() };

enum groupLabels : std::size_t
{
    groupMap,
    groupPlayers,
    groupEnemies,
    groupColliders
};

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

    Map::loadMap("../../assets/first.map", 25, 20);

    player.addComponent<TransformComponent>(1);
    player.addComponent<SpriteComponent>("../../assets/player.png");
    player.addComponent<KeyboardController>();
    player.addComponent<ColliderComponent>("player");
    player.addGroup(groupPlayers);


    // wall.addComponent<TransformComponent>( 300.0f, 300.0f, 300, 20, 1);
    // wall.addComponent<SpriteComponent>( "../../assets/stonewall.png");
    // wall.addComponent<ColliderComponent>("wall");
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

    for (auto cc : colliders)
    {
        Collision::AABB(player.getComponent<ColliderComponent>(), *cc);        
    }
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayers));
auto& enemies(manager.getGroup(groupEnemies));

void Game::render()
{
    SDL_RenderClear( renderer );
    //To render texture to screen
   
    for (auto& t : tiles)
    {
        t->draw();
    }
    for (auto& p : players)
    {
        p->draw();
    }
    for (auto& e : enemies)
    {
        e->draw();
    }

    SDL_RenderPresent(renderer);
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

void Game::addTile(int id, int x, int y)
{
    auto& tile(manager.addEntity());
    tile.addComponent<TileComponent>(x, y, 32, 32, id);
    tile.addGroup(groupMap);
}
