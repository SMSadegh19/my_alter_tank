//
// Created by sadegh on 12/19/18.
//

#include "physics.h"
#include "structs.h"
#include "logic.h"
#include <math.h>

void bullets_moving(Map *map) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (map->tank[i].bullet[j].is_fired) {
                move_bullet(&(map->tank[i].bullet[j]), map);
            }
        }
    }
}

void move_bullet(Bullet *bullet, Map *map) {
    bullet_collid_wall(bullet, map);
    bullet->x += (int)(cos(bullet->angle) * 10);
    bullet->y += (int)(sin(bullet->angle) * 10);
    bullet_collid_tank(bullet, map);
    bullet->remained_life -= 1;
    if (bullet->remained_life <= 0) {
        bullet->is_fired = 0;
    }
}

void move_tank(Map *map) {
    for (int i = 0; i < 3; ++i) {
        if (map->tank[i].key_pressed[0]) {
            go_backward(&(map->tank[i]), map);
        }
        if (map->tank[i].key_pressed[1]) {
            go_forward(&(map->tank[i]), map);
        }
    }
}

void go_forward(Tank *tank, Map *map) {
    int temp_x = tank->x + (int)(cos(tank->angle) * 8);
    int temp_y = tank->y + (int)(sin(tank->angle) * 8);
    if (!tank_movement_collid(map, temp_x, temp_y)) {
        tank->x += (int)(cos(tank->angle) * 8);
        tank->y += (int)(sin(tank->angle) * 8);
    }
}

void go_backward(Tank *tank, Map *map) {
    int temp_x = tank->x - (int)(cos(tank->angle) * 5);
    int temp_y = tank->y - (int)(sin(tank->angle) * 5);
    if (!tank_movement_collid(map, temp_x, temp_y)) {
        tank->x -= (int)(cos(tank->angle) * 5);
        tank->y -= (int)(sin(tank->angle) * 5);
    }
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
    if (tank->is_alive == 0) {
        return;
    }
    for (int i = 0; i < 6; ++i) {
        if (tank->bullet[i].is_fired == 0) {
            //initializing bullet
            tank->bullet[i].remained_life = 100;
            tank->bullet[i].x = tank->x + (int) ((tank_radius + 3) * cos(tank->angle));
            tank->bullet[i].y = tank->y + (int) ((tank_radius + 3) * sin(tank->angle));
            tank->bullet[i].angle = tank->angle;
            tank->bullet[i].is_fired = 1;
            tank->bullet[i].in_wall = 0;
            break;
        }
    }
}