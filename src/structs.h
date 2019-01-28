//
// Created by sadegh on 12/19/18.
//

#ifndef TANK_STRUCTS_H
#define TANK_STRUCTS_H

typedef struct {
    int x;
    int y;
    int is_planted;
    int frame_from_born;
    int is_in_range;
    int frame_from_in_range;
} Mine;

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
    int is_released;
    Bullet bullet[9];
} FragBomb;

typedef struct {
    int x;
    int y;
    int score;
    double angle;
    int is_alive;
    int powered_up;
    int frag_section;//0:No frag Bomb ** 1:Has Frag ** 2:Released
    int have_mine;
    int key_pressed[4];//0 : backward ** 1 : forward ** 2 : right_turn ** 3 : left_turn
    FragBomb fragBomb;
    Bullet bullet[6];
    int color[3];
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
    int number_of_walls;//saved
    long long int frames;//saved
    Powerup powerup[5];//saved
    Mine mine[15];//saved
    Tank tank[3];//saved
    Wall *walls;//saved
} Map;

#endif //TANK_STRUCTS_H