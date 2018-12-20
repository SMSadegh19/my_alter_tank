//
// Created by sadegh on 12/19/18.
//

#include "view.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

SDL_Window *window;
SDL_Renderer *renderer;

int tank_radius = 30;

void init_window() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return;
    window = SDL_CreateWindow("SDL_RenderClear",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              1000, 550,
                              SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void render_clear() {
    SDL_SetRenderDrawColor(renderer, rand(), 200, 200, 255);
    SDL_RenderClear(renderer);
}

void present_window() {
    SDL_RenderPresent(renderer);
    SDL_Delay(30);
}

void quit_window() {
    SDL_Quit();
}

void draw_tank(Tank *tank) {
    filledCircleRGBA(renderer, tank->x, tank->y, tank_radius, tank->color[0], tank->color[1], tank->color[2], 255);
}

