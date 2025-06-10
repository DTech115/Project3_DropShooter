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

	boundx = 800;
	boundy = 50;
	x = 355;
	y = 650;
	lives = 5;
	score = 0;
}

void player::DrawPlayer()
{
	decorAngle += 0.2;
	//main sprite
	al_draw_bitmap(reimu, x, y, 0);
	al_draw_rotated_bitmap(yinyang, 32, 32, 300, 750, decorAngle, 0);
	al_draw_rotated_bitmap(yinyang, 32, 32, 500, 750, -decorAngle, 0);

	//cannon
	al_draw_rotated_bitmap(yinyang, 32, 128, 400, 700, angle, 0);
}

//converted to radians
void player::MoveLeft()
{
	angle -= 0.1;
	if (angle < -1)
	{
		angle = -1;
	}
}
void player::MoveRight()
{
	angle += 0.1;
	if (angle > 1.0)
	{
		angle = 1.0;
	}
}
