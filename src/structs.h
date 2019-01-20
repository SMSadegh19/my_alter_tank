//
// Created by sadegh on 12/19/18.
//

#ifndef TANK_STRUCTS_H
#define TANK_STRUCTS_H

typedef struct {
    int in_wall;
    int x;
    int y;
    double angle;
    int is_fired;
    int remained_life;//first 100
} Bullet;

typedef struct {
    int x;
    int y;
    int score;
    int color[3];
    double angle;
    int is_alive;
    int key_pressed[4];//0 : backward //1 : forward //2 : right_turn //3 : left_turn
    Bullet bullet[6];
} Tank;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
    int vertical;//1: means vertical //0: means horizontal
} Wall;

typedef struct {
    int game_pause;
    int number_of_walls;
    Tank tank[3];
    Wall *walls;
} Map;

#endif //TANK_STRUCTS_H
