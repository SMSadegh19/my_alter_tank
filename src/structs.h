//
// Created by sadegh on 12/19/18.
//

#ifndef TANK_STRUCTS_H
#define TANK_STRUCTS_H

typedef struct {
    int x;
    int y;
    //0: Frag Bomb ** 1: Mine ** 2: Laser ** 3: SlowMotion ** 4: Freeze
    int type;
    //0: All will have this ** 1:For others ** 2:Just for you
    int use_by;
    int is_on;
} Powerup;

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
    int powered_up;
    int frag_section;//0:No frag Bomb ** 1:Has Frag ** 2:Released
    int key_pressed[4];//0 : backward ** 1 : forward ** 2 : right_turn ** 3 : left_turn
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
    int first_menu;
    int number_of_walls;
    long long int frames;
    Powerup powerup[5];
    Tank tank[3];
    Wall *walls;
} Map;

#endif //TANK_STRUCTS_H
