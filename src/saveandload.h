//
// Created by sadegh on 1/28/19.
//

#include "structs.h"
#include "logic.h"
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#ifndef TANK_SAVEANDLOAD_H
#define TANK_SAVEANDLOAD_H

void save_game(Map *map);
void save_bullet_information(FILE *file, Bullet *bullet);
int number_of_saves();
void load_game(Map *map, int load_number);
void load_bullet_information(FILE *file, Bullet *bullet);
int get_load_number(Map *map, SDL_Renderer *renderer);

#endif //TANK_SAVEANDLOAD_H
