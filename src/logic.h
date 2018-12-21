//
// Created by sadegh on 12/20/18.
//

#include "structs.h"
#include "view.h"

#ifndef TANK_LOGIC_H
#define TANK_LOGIC_H

void generate_map(Map *map);
    int exist_0_vertex();
int tank_movement_collid(Map *map, int temp_x, int temp_y);
int bullet_collid(Bullet *bullet, Map *map);

#endif //TANK_LOGIC_H
