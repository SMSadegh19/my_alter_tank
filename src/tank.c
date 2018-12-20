//
// Created by sadegh on 12/16/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "structs.h"
#include "view.h"
#include "physics.h"


int main() {
    init_window();
    Tank tank_1 = {};
    int s_continue = 1;//to realize should continue or no??
    while(s_continue) {
        render_clear();
//      start of drawing

//      end of drawing
        present_window();
    }
    quit_window();
    return 0;
}