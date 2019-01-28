//
// Created by sadegh on 1/28/19.
//

#include "structs.h"
#include <stdio.h>

#ifndef TANK_SAVEANDLOAD_H
#define TANK_SAVEANDLOAD_H

void save_game(Map *map);
void save_bullet_information(FILE *file, Bullet *bullet);
void load_game(Map *map);
void load_bullet_information(FILE *file, Bullet *bullet);

#endif //TANK_SAVEANDLOAD_H
