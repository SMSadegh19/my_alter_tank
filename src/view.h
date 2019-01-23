//
// Created by sadegh on 12/19/18.
//

#include "structs.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#ifndef TANK_VIEW_H
#define TANK_VIEW_H

extern const double pi;
extern int EXIT;
extern int tank_radius;
extern int is_selected;
extern int FPS;

//initializing functions
void initialize_game_values(Map *map);
void zero_key_pressed(Map *map);
void tanks_rand_place(Map *map);
//SDL presents
void init_window();
void render_clear();
void present_window();
void quit_window();
//Drawings
void draw_shapes(Map *map);
void draw_scores(Map *map);
void draw_first_menu();
void draw_button(char *string, int x, int y, int a, int b, int NUMBER, int alpha);
void draw_game_menu();
void draw_tank(Tank *tank);
void draw_tank_gun(Tank *tank);
void draw_bullet(Bullet *bullet);
void draw_walls(Map *map);
void draw_wall(Wall *wall);
//Event handling
int event_handling(Map *map);

#endif //TANK_VIEW_H
