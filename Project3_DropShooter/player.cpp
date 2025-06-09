//DT Nesimi

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"

player::~player()
{
	al_destroy_bitmap(reimu);
	al_destroy_bitmap(yinyang);

}
player::player()
{

	reimu = al_load_bitmap("reimu.png");
	yinyang = al_load_bitmap("yinyang.png");

	boundx = al_get_bitmap_width(reimu);
	boundy = al_get_bitmap_height(reimu);
	x = 350;
	y = 650;
	lives = 5;
	score = 0;
}

void player::DrawPlayer()
{
	al_draw_bitmap(reimu, x, y, 0);
	al_draw_rotated_bitmap(yinyang, 32, 32, 400, 600, angle, 0);
}

void player::MoveLeft()
{
	angle -= 0.1;
	if (angle < 0)
	{
		angle += ALLEGRO_PI * 2;
	}
	if (angle < 1.5 && angle> 0.5)
	{
		angle = 1.5;
	}
}
void player::MoveRight()
{
	
}
