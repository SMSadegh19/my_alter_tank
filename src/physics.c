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
        if (map->tank[i].fragBomb.is_released) {
            Bullet *purpose = &(map->tank[i].fragBomb.bullet[0]);
            if (purpose->is_fired) {
                move_bullet(purpose, map);
            }
        }
        for (int j = 1; j < 9; ++j) {
            Bullet *purpose = &(map->tank[i].fragBomb.bullet[j]);
            if (purpose->is_fired) {
                move_bullet(purpose, map);
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
        get_powerup(map, &(map->tank[i]));
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
    if (tank->frag_section == 2) {
        tank->fragBomb.is_released = 0;
        tank->fragBomb.bullet[0].is_fired = 0;
        for (int i = 1; i < 9; ++i) {
            Bullet *purpose = &(tank->fragBomb.bullet[i]);
            Bullet *refrence = &(tank->fragBomb.bullet[0]);
            purpose->remained_life = 100;
            purpose->x = refrence->x;
            purpose->y = refrence->y;
            purpose->angle = (i - 1) * (pi / 4) + (pi / 9);
            purpose->is_fired = 1;
            purpose->in_wall = 0;
        }
        //explode it
        tank->frag_section = 0;
        tank->powered_up = 0;
        return;
    }
    if (tank->is_alive == 0) {
        return;
    }
    if (tank->frag_section == 1) {
        //code for when remained life to 0 . I think is OK
        tank->fragBomb.bullet[0].remained_life = 1000;
        tank->fragBomb.bullet[0].x = tank->x + (int) ((tank_radius + 3) * cos(tank->angle));
        tank->fragBomb.bullet[0].y = tank->y + (int) ((tank_radius + 3) * sin(tank->angle));
        tank->fragBomb.bullet[0].angle = tank->angle;
        tank->fragBomb.bullet[0].is_fired = 1;
        tank->fragBomb.bullet[0].in_wall = 0;
        tank->fragBomb.is_released = 1;
        //release it
        tank->frag_section = 2;
        return;
    }
    for (int i = 0; i < 6; ++i) {
        if (tank->bullet[i].is_fired == 0) {
            //initializing bullet
            tank->bullet[i].remained_life = 250;
            tank->bullet[i].x = tank->x + (int) ((tank_radius + 3) * cos(tank->angle));
            tank->bullet[i].y = tank->y + (int) ((tank_radius + 3) * sin(tank->angle));
            tank->bullet[i].angle = tank->angle;
            tank->bullet[i].is_fired = 1;
            tank->bullet[i].in_wall = 0;
            break;
        }
    }
}