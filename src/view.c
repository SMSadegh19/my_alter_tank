//
// Created by sadegh on 12/19/18.
//

#include "view.h"
#include "structs.h"
#include "logic.h"
#include "physics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <time.h>

const double pi = 3.141592;
int EXIT = 10000;

SDL_Window *window;
SDL_Renderer *renderer;
int tank_radius = 18;
int x_max = 10 * 100;
int y_max = 6 * 100;

void initialize_game_values(Map *map) {
    srand(time(NULL));
    for (int i = 0; i < 3; ++i) {
        map->tank[i].x = rand() % x_max;
        map->tank[i].y = rand() % y_max;
        map->tank[i].angle = (rand() % 360) * pi / 180;
        map->tank[i].is_alive = 1;
        map->tank[i].score = 0;
        for (int j = 0; j < 3; ++j) {
            if (i != j) {
                map->tank[i].color[j] = 50;
            } else {
                map->tank[i].color[j] = 255;
            }
        }
        for (int k = 0; k < 6; ++k) {
            map->tank[i].bullet[k].is_fired = 0;
        }
        for (int r = 0; r < 4; ++r) {
            map->tank[i].key_pressed[r] = 0;
        }
    }
}

void init_window() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;
    window = SDL_CreateWindow("SDL_RenderClear",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              x_max, y_max,
                              SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void render_clear() {
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
    SDL_RenderClear(renderer);
}

void present_window() {
    SDL_RenderPresent(renderer);
    SDL_Delay(30);
}

void quit_window() {
    SDL_Quit();
}

void draw_shapes(Map *map) {
    draw_walls(map);
    for (int i = 0; i < 3; ++i) {
        if (map->tank[i].is_alive) {
            draw_tank(&(map->tank[i]));
        }
        for (int j = 0; j < 6; ++j) {
            if (map->tank[i].bullet[j].is_fired) {
                draw_bullet(&(map->tank[i].bullet[j]));
            }
        }
    }
}

void draw_walls(Map *map) {
    for (int i = 0; i < map->number_of_walls; ++i) {
        draw_wall(map->walls + i);
    }
}

void draw_wall(Wall *wall) {
    lineRGBA(renderer, wall->x1 * 100, wall->y1 * 100, wall->x2 * 100, wall->y2 * 100, 0, 0, 0, 255);
}

void draw_tank(Tank *tank) {
    filledCircleRGBA(renderer, tank->x, tank->y, tank_radius, tank->color[0], tank->color[1], tank->color[2], 255);
    draw_tank_gun(tank);
}

void draw_bullet(Bullet *bullet) {
    filledCircleRGBA(renderer, bullet->x, bullet->y, 3, 20, 20, 20, 255);
}

void draw_tank_gun(Tank *tank) {
    int x_gun = tank->x + (int) ((tank_radius + 3) * cos(tank->angle));
    int y_gun = tank->y + (int) ((tank_radius + 3) * sin(tank->angle));
    filledCircleRGBA(renderer, x_gun, y_gun, 5, 90, 90, 90, 255);
}

int event_handling(Map *map) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT)
            return EXIT;
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                //tank0
                case SDLK_DOWN:
                    map->tank[0].key_pressed[0] = 1;
                    break;
                case SDLK_UP:
                    map->tank[0].key_pressed[1] = 1;
                    break;
                case SDLK_RIGHT:
                    map->tank[0].key_pressed[2] = 1;
                    break;
                case SDLK_LEFT:
                    map->tank[0].key_pressed[3] = 1;
                    break;
                //tank1
                case SDLK_d:
                    map->tank[1].key_pressed[0] = 1;
                    break;
                case SDLK_e:
                    map->tank[1].key_pressed[1] = 1;
                    break;
                case SDLK_f:
                    map->tank[1].key_pressed[2] = 1;
                    break;
                case SDLK_s:
                    map->tank[1].key_pressed[3] = 1;
                    break;
                //tank2
                case SDLK_KP_5:
                    map->tank[2].key_pressed[0] = 1;
                    break;
                case SDLK_KP_8:
                    map->tank[2].key_pressed[1] = 1;
                    break;
                case SDLK_KP_6:
                    map->tank[2].key_pressed[2] = 1;
                    break;
                case SDLK_KP_4:
                    map->tank[2].key_pressed[3] = 1;
                    break;
            }
        } else if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                //tank0
                case SDLK_DOWN:
                    map->tank[0].key_pressed[0] = 0;
                    break;
                case SDLK_UP:
                    map->tank[0].key_pressed[1] = 0;
                    break;
                case SDLK_RIGHT:
                    map->tank[0].key_pressed[2] = 0;
                    break;
                case SDLK_LEFT:
                    map->tank[0].key_pressed[3] = 0;
                    break;
                case SDLK_m:
                    fire(&(map->tank[0]));
                    break;
                //tank1
                case SDLK_d:
                    map->tank[1].key_pressed[0] = 0;
                    break;
                case SDLK_e:
                    map->tank[1].key_pressed[1] = 0;
                    break;
                case SDLK_f:
                    map->tank[1].key_pressed[2] = 0;
                    break;
                case SDLK_s:
                    map->tank[1].key_pressed[3] = 0;
                    break;
                case SDLK_q:
                    fire(&(map->tank[1]));
                    break;
                //tank2
                case SDLK_KP_5:
                    map->tank[2].key_pressed[0] = 0;
                    break;
                case SDLK_KP_8:
                    map->tank[2].key_pressed[1] = 0;
                    break;
                case SDLK_KP_6:
                    map->tank[2].key_pressed[2] = 0;
                    break;
                case SDLK_KP_4:
                    map->tank[2].key_pressed[3] = 0;
                    break;
                case SDLK_KP_0:
                    fire(&(map->tank[2]));
                    break;
            }
        }
    }
    move_tank(map);
    turn_tank(map);
}