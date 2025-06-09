//DT Nesimi

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"

player::~player()
{
	al_destroy_bitmap(reimu);

}
player::player()
{

	reimu = al_load_bitmap("reimu.png");

	x = 400;
	y = 700;
	lives = 5;
	boundx = al_get_bitmap_width(reimu);
	boundy = al_get_bitmap_height(reimu);
	score = 0;
}

void player::DrawPlayer()
{
	al_draw_bitmap(reimu, x, y, 0);
}

void player::MoveUp()
{
	
}
void player::MoveDown(int HEIGHT)
{
	
}
void player::MoveLeft()
{
	
}
void player::MoveRight()
{
	
}
