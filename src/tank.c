//
// Created by sadegh on 12/16/18.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>


int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;

    /* Initialize SDL. */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    /* Create the window where we will draw. */
    window = SDL_CreateWindow("SDL_RenderClear",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              1000, 550,
                              SDL_WINDOW_OPENGL);

    /* We must call SDL_CreateRenderer in order for draw calls to affect this window. */
    renderer = SDL_CreateRenderer(window, -1, 0);
    int a = 1;
    while(a) {
    /* Select the color for drawing. It is set to red here. */
    SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);

    /* Clear the entire screen to our selected color. */
    SDL_RenderClear(renderer);
    
    //start of drawing

    //end of drawing


    SDL_RenderPresent(renderer);

    /* Give us time to see the window. */
    SDL_Delay(30);
    }

    /* Always be sure to clean up */
    SDL_Quit();
    return 0;
}