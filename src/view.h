//
// Created by sadegh on 12/19/18.
//

#include "structs.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#ifndef TANK_VIEW_H
#define TANK_VIEW_H

void initialize_game_values(Map *map);
void init_window();
void render_clear();
void present_window();
void quit_window();
void draw_shapes(Map *map);
void draw_tank(Tank *tank);
void draw_bullet(Bullet *bullet);
void draw_walls(Wall *walls);
void handle_events(Map *map);

#endif //TANK_VIEW_H
