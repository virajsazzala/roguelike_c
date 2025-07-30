#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

typedef struct Sprite
{
    Texture2D texture;
    Rectangle sprite_box;
    Rectangle source_box;
    Vector2 origin;
    float rotation;
} Sprite;

#endif