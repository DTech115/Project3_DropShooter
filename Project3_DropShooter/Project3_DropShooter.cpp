//DT Nesimi
#include <iostream>

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5/allegro_ttf.h>

//moving background method!
void scrollBackground();

//background global vars & dimensions
ALLEGRO_BITMAP* bg = NULL;
ALLEGRO_BITMAP* moon = NULL;
float bg_y1 = 0;
float bg_y2 = 0;
float scroll_speed = 2.0;
float moonAngle = 0.0;

const int WIDTH = 800;
const int HEIGHT = 800;

int main()
{
    
    const int NUM_ArrowS = 5;
    const int NUM_ghostS = 10;
    enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };
    bool keys[5] = { false, false, false, false, false };

    //primitive variable
    bool done = false;
    bool redraw = true;
    const int FPS = 60;
    bool gameOver = false; //	gameover check for drawing gameover text

    //Allegro variables
    ALLEGRO_DISPLAY* display = NULL;
    ALLEGRO_EVENT_QUEUE* event_queue = NULL;
    ALLEGRO_TIMER* timer = NULL;

    //Initialization Functions
    if (!al_init())										//initialize Allegro
        return -1;

    display = al_create_display(WIDTH, HEIGHT);			//create our display object

    if (!display)										//test display object
        return -1;

    al_install_keyboard();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_FONT* gameoverFont = al_load_font("DFPPOPCorn-W12.ttf", 32, 0);		//game font
    ALLEGRO_FONT* mainFont = al_load_font("DFPPOPCorn-W12.ttf", 18, 0);		//font

    //object variables
    /*player myPlayer(HEIGHT);
    Arrow Arrows[NUM_ArrowS];
    ghost ghosts[NUM_ghostS];*/

    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);

    srand(time(NULL));

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_start_timer(timer);

    bg = al_load_bitmap("background.png");
    moon = al_load_bitmap("moon.png");

    bg_y1 = 0;
    bg_y2 = -al_get_bitmap_height(bg);

    //game loop
    while (!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;

            scrollBackground();
            al_draw_bitmap(moon, 140, 60, 0);
           
            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));

            /*Left Keyboard Call
                Call rotate cannon
                Right Keyboard
                Call rotate cannon
                Update Snowballs
                Start Penguins Dropping
                Update Penguins Dropping
                Collide Snowballs
                Collide Penguins*/
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_UP:
                keys[UP] = true;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = true;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = true;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = true;
                break;
            case ALLEGRO_KEY_SPACE:
                keys[SPACE] = true;
                /*for (int i = 0; i < NUM_SNOWBALLS; i++)
                    snowballs.FireSnowballs(penguinFiring);*/
                break;
            }
        }
        else if (ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch (ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;
            case ALLEGRO_KEY_UP:
                keys[UP] = false;
                break;
            case ALLEGRO_KEY_DOWN:
                keys[DOWN] = false;
                break;
            case ALLEGRO_KEY_LEFT:
                keys[LEFT] = false;
                break;
            case ALLEGRO_KEY_RIGHT:
                keys[RIGHT] = false;
                break;
            case ALLEGRO_KEY_SPACE:
                keys[SPACE] = false;
                break;
            }
        }
        if (redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;
            /*draw background
                draw iceberg
                draw penguinFiring
                draw snowballs
                draw penguin Dropping
                al_flip_display();*/
            al_clear_to_color(al_map_rgb(0, 0, 0));
        }
    }

    al_destroy_bitmap(bg);
}


void scrollBackground() {
    // Move both backgrounds down
    bg_y1 += scroll_speed;
    bg_y2 += scroll_speed;
    //moonAngle += 0.007;

    // Reset if they're off screen
    if (bg_y1 >= HEIGHT)
        bg_y1 = bg_y2 - al_get_bitmap_height(bg);
    if (bg_y2 >= HEIGHT)
        bg_y2 = bg_y1 - al_get_bitmap_height(bg);

    // Draw both bitmaps
    al_draw_bitmap(bg, 0, bg_y1, 0);
    al_draw_bitmap(bg, 0, bg_y2, 0);
    //al_draw_rotated_bitmap(moon, al_get_bitmap_width(moon) / 2.0, al_get_bitmap_width(moon) / 2.0, 400, 300, moonAngle, 0);

}