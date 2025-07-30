#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

void init_player(Sprite *player, Texture2D texture);
void move_player(Sprite *player);
void draw_player(Sprite *player);

#endif