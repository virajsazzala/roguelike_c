#include <stdio.h>
#include <raylib.h>

#include "entity/player.h"

int main()
{

	InitWindow(600, 400, "RogueLike, but in C");
	SetTargetFPS(60);

	Texture2D player_texture = LoadTexture("assets/dejavu10x10_gs_tc.png");

	Sprite player;
	init_player(&player, player_texture);

	while (!WindowShouldClose())
	{
		move_player(&player);

		BeginDrawing();

		ClearBackground(BLACK);
		draw_player(&player);

		EndDrawing();
	}

	UnloadTexture(player_texture);
	CloseWindow();

	return 0;
}
