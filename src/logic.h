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
void add_score(Map *map);
int is_two_dead(Map *map);
void bullet_collid_tank(Bullet *bullet, Map *map);
void bullet_collid_wall(Bullet *bullet, Map *map);
void mine_features_controlling(Map *map);
void tank_on_mine_range(Map *map, Tank *tank, Mine *mine, int to_destroy);
void kill_tank(Map *map, Tank *tank);
//powerups
void power_in_myplace(Tank *tank, Powerup *powerup);
void get_powerup(Map *map, Tank *tank);
void set_a_powerup(Map *map);

#endif //TANK_LOGIC_H
