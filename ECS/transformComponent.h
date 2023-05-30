#ifndef TRANSFORMCOMPONENT_H
#define TRANSFORMCOMPONENT_H

#include "components.h"
#include "../vector2D.h"

class TransformComponent : public Component
{
public:
    Vector2D position;
    Vector2D velocity;

    int height{ 32 };
    int width{ 32 };
    int scale{ 1 };

    int speed{ 3 };

    TransformComponent()
    {
        position.zero();
    }
    TransformComponent( int sc ) : scale{ sc }
    {
        position.zero();
    }
    TransformComponent( float x, float y)
    {
        position.set( x, y );
    }
     TransformComponent( float x, float y, int h, int w, int sc) 
     : height{ h }, width{ w }, scale{ sc }
    {
        position.set( x, y );
    }
    void update() override
    {
       position += velocity * speed;
    }
    void init() override
    {
        velocity.zero();
    }
};

#endif
