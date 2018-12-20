//
// Created by sadegh on 12/19/18.
//

#include "view.h"
#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

const double pi = 3.141592;

SDL_Window *window;
SDL_Renderer *renderer;
int tank_radius = 30;
int x_max = 1000;
int y_max = 550;

void initialize_game_values(Map *map) {
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
    for (int i = 0; i < 3; ++i) {
        draw_tank(&(map->tank[i]));
    }
}

void draw_tank(Tank *tank) {
    filledCircleRGBA(renderer, tank->x, tank->y, tank_radius, tank->color[0], tank->color[1], tank->color[2], 255);
    draw_tank_gun(tank);
}

void draw_tank_gun(Tank *tank) {
    int x_gun = tank->x + (int) ((tank_radius + 3) * cos(tank->angle));
    int y_gun = tank->y + (int) ((tank_radius + 3) * sin(tank->angle));
    filledCircleRGBA(renderer, x_gun, y_gun, 5, 90, 90, 90, 255);
}