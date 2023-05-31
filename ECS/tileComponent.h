#ifndef TILECOMPONENT_H
#define TILECOMPONENT_H

#include "ECS.h"
#include "transformComponent.h"
#include "SDL2/SDL.h"

class TileComponent : public Component
{
public:
    TransformComponent* transform;
    SpriteComponent* sprite;

    SDL_Rect tileRect;
    int tileID;
    char* path;


    TileComponent() = default;

    TileComponent( int x, int y, int w, int h, int id ) : tileID{ id }
    {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;

        switch(tileID)
        {
            case 0:
                path = "../../assets/water.png";
                break;
            case 1:
                path = "../../assets/dirt.png";
                break;
            case 2:
                path = "../../assets/grass.png";
                break;
            case 3:
                path = "../../assets/stonewall.png";
                break;
            default:
                break;
        }
    }    
    void init() override
    {
        entity->addComponent<TransformComponent>(static_cast<float>(tileRect.x), static_cast<float>(tileRect.y), tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();

        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};

#endif
