//
// Created by sadegh on 12/19/18.
//

#include "structs.h"
#include "view.h"

#ifndef TANK_PHYSICS_H
#define TANK_PHYSICS_H

void move_tank(Map *map);
void go_forward(Tank *tank, Map *map);
void go_backward(Tank *tank, Map *map);
void turn_tank(Map *map);
void fire(Tank *tank);
void bullets_moving(Map *map);
void move_bullet(Bullet *bullet, Map *map);

#endif //TANK_PHYSICS_H
