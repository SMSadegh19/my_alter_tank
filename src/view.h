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
extern int NOS;
extern int audio_frames;
extern long long int time_passed_during_game;
extern int x_max;
extern int y_max;

//initializing functions
void initialize_game_values(Map *map);
void zero_key_pressed(Map *map);
void tanks_rand_place(Map *map);
void powerup_rand_place(Powerup *powerup);
//SDL presents
void init_window();
void render_clear();
void present_window();
void quit_window();
//Drawings
void draw_background();
void draw_results(Map *map);
void draw_shapes(Map *map);
void draw_scores(Map *map);
void draw_first_menu(Map *map);
void draw_button(char *string, int x, int y, int a, int b, int NUMBER, int alpha);
void draw_game_menu();
void draw_tank(Tank *tank);
void draw_tank_gun(Tank *tank);
void draw_bullet(Bullet *bullet);
void draw_walls(Map *map);
void draw_wall(Wall *wall);
void draw_powerup(Powerup *powerup);
void draw_bomb(Bullet *bullet);
void draw_mine(Mine *mine);
void draw_dancing_lines(Map *map, SDL_Renderer *sdl_renderer);
//Event handling
int event_handling(Map *map);
//helper
char *convert_number_to_string(long long int number);

#endif //TANK_VIEW_H
