//
// Created by sadegh on 12/19/18.
//

#include "physics.h"
#include "structs.h"
#include <math.h>

void move_tank(Map *map) {
    for (int i = 0; i < 3; ++i) {
        if (map->tank[i].key_pressed[0]) {
            go_backward(&(map->tank[i]));
        }
        if (map->tank[i].key_pressed[1]) {
            go_forward(&(map->tank[i]));
        }
    }
}

void go_forward(Tank *tank) {
    tank->x += (int)(cos(tank->angle) * 10);
    tank->y += (int)(sin(tank->angle) * 10);
}

void go_backward(Tank *tank) {
    tank->x -= (int)(cos(tank->angle) * 10);
    tank->y -= (int)(sin(tank->angle) * 10);
}

void turn_tank(Map *map) {
    for (int i = 0; i < 3; ++i) {
        if (map->tank[i].key_pressed[2]) {
            map->tank[i].angle += (5 * 3.141592) / 180;
        }
        if (map->tank[i].key_pressed[3]) {
            map->tank[i].angle -= (5 * 3.141592) / 180;
        }
    }
}

void fire(Tank *tank) {

}