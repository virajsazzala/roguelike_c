#include "entity/player.h"

void init_player(Sprite *player, Texture2D texture)
{
    int sprite_size = 10;
    int col = 0;
    int row = 1;

    *player = (Sprite){
        .texture = texture,
        .sprite_box = (Rectangle){10.0f, 100.0f, 100.0f, 100.0f},
        .source_box = (Rectangle){col * sprite_size, row * sprite_size, sprite_size, sprite_size},
        .origin = (Vector2){0, 0},
        .rotation = 0.0f};
}

void move_player(Sprite *player)
{
    Vector2 velocity = {0};

    if (IsKeyDown(KEY_D))
        velocity.x += 1;
    if (IsKeyDown(KEY_A))
        velocity.x -= 1;
    if (IsKeyDown(KEY_W))
        velocity.y -= 1;
    if (IsKeyDown(KEY_S))
        velocity.y += 1;

    if (velocity.x != 0 || velocity.y != 0)
    {
        float length = sqrtf(velocity.x * velocity.x + velocity.y * velocity.y);
        velocity.x /= length;
        velocity.y /= length;
    }

    float speed = 100.0f;
    player->sprite_box.x += roundf(velocity.x * speed * GetFrameTime());
    player->sprite_box.y += roundf(velocity.y * speed * GetFrameTime());
}

void draw_player(Sprite *player)
{
    DrawTexturePro(player->texture, player->source_box, player->sprite_box, player->origin, player->rotation, RAYWHITE);
}