#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "../textureManager.h"
#include "components.h"

#include <SDL2/SDL.h>

class SpriteComponent: public Component
{
private:
    TransformComponent* transform;
    SDL_Texture* texture;

    SDL_Rect srcRect;
    SDL_Rect destRect;

public:
    SpriteComponent() = default;
    SpriteComponent( const char* path ) 
    {
        setTex( path );
    }
    ~SpriteComponent()
    {
        SDL_DestroyTexture( texture );
    }

    void setTex( const char* path )
    {
        texture = TextureManager::loadTexture( path );
    }

    void init() override
    {
        transform = &entity->getComponent<TransformComponent>();

        srcRect.x = 0;
        srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;

        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
    }

    void update() override
    {
        destRect.x = static_cast<int>( transform->position.x );
        destRect.y = static_cast<int>( transform->position.y );
    }

    void draw() override
    {
        TextureManager::draw( texture, srcRect, destRect );
    }



};


#endif
