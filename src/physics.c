//
// Created by sadegh on 12/19/18.
//

#include "physics.h"
#include "structs.h"
#include <math.h>

void bullets_moving(Map *map) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (map->tank[i].bullet[j].is_fired) {
                move_bullet(&(map->tank[i].bullet[j]));
            }
        }
    }
}

void move_bullet(Bullet *bullet) {
    bullet->x += (int)(cos(bullet->angle) * 10);
    bullet->y += (int)(sin(bullet->angle) * 10);
    bullet->remained_life -= 1;
    if (bullet->remained_life <= 0) {
        bullet->is_fired = 0;
    }
}

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
    for (int i = 0; i < 6; ++i) {
        if (tank->bullet[i].is_fired == 0) {
            //initializing bullet
            tank->bullet[i].remained_life = 100;
            tank->bullet[i].x = tank->x;
            tank->bullet[i].y = tank->y;
            tank->bullet[i].angle = tank->angle;
            tank->bullet[i].is_fired = 1;
            break;
        }
    }
}