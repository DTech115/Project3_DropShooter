//DT Nesimi

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include "player.h"

player::~player()
{
	al_destroy_bitmap(reimu);
	al_destroy_bitmap(yinyang);
	al_destroy_bitmap(giantseal);

	al_destroy_bitmap(giantsealL1);
	al_destroy_bitmap(giantsealL2);
	al_destroy_bitmap(giantsealL3);
	al_destroy_bitmap(giantsealR1);
	al_destroy_bitmap(giantsealR2);
	al_destroy_bitmap(giantsealR3);
	al_destroy_bitmap(giantsealR4);
	al_destroy_bitmap(emptyseal);

	al_destroy_bitmap(yinyangL1);
	al_destroy_bitmap(yinyangL2);
	al_destroy_bitmap(yinyangL3);
	al_destroy_bitmap(yinyangL4);
	al_destroy_bitmap(yinyangL5);
	al_destroy_bitmap(yinyangR1);
	al_destroy_bitmap(yinyangR2);
	al_destroy_bitmap(yinyangR3);
	al_destroy_bitmap(yinyangR4);
	al_destroy_bitmap(yinyangR5);

	al_destroy_bitmap(power);

}
player::player()
{
	reimu = al_load_bitmap("reimu.png");
	yinyang = al_load_bitmap("yinyang.png");

	yinyangL1 = al_load_bitmap("yinyangL1.png");
	yinyangL2 = al_load_bitmap("yinyangL2.png");
	yinyangL3 = al_load_bitmap("yinyangL3.png");
	yinyangL4 = al_load_bitmap("yinyangL4.png");
	yinyangL5 = al_load_bitmap("yinyangL5.png");
	yinyangR1 = al_load_bitmap("yinyangR1.png");
	yinyangR2 = al_load_bitmap("yinyangR2.png");
	yinyangR3 = al_load_bitmap("yinyangR3.png");
	yinyangR4 = al_load_bitmap("yinyangR4.png");
	yinyangR5 = al_load_bitmap("yinyangR5.png");

	giantseal = al_load_bitmap("giantseal.png");
	giantsealL1 = al_load_bitmap("giantsealL1.png");
	giantsealL2 = al_load_bitmap("giantsealL2.png");
	giantsealL3 = al_load_bitmap("giantsealL3.png");
	giantsealR1 = al_load_bitmap("giantsealR1.png");
	giantsealR2 = al_load_bitmap("giantsealR2.png");
	giantsealR3 = al_load_bitmap("giantsealR3.png");
	giantsealR4 = al_load_bitmap("giantsealR4.png");
	emptyseal = al_load_bitmap("emptyseal.png");

	power = al_load_bitmap("power.png");


	boundx = 800;
	boundy = 50;
	x = 355;
	y = 650;
	lives = 6;
	score = 0;
}

void player::DrawPlayer()
{
	decorAngle += 0.2;
	//main sprite
	/*if (lives >= 5) {
	}
	else if (lives == 4) {
	}
	else if (lives == 3) {
	}
	else if (lives == 2) {
	}
	else if (lives <= 1) {
	}*/
	al_draw_bitmap(reimu, x, y, 0);
	al_draw_rotated_bitmap(yinyang, 32, 32, 300, 750, decorAngle, 0);
	al_draw_rotated_bitmap(yinyang, 32, 32, 500, 750, -decorAngle, 0);
	al_draw_bitmap(giantseal, x-250, y, 0);
	al_draw_bitmap(giantseal, x + 270, y, 0);

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
