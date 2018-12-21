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
#include "logic.h"

Map game_map;

int main() {
    game_map.walls = malloc(sizeof(Wall) * 100);
    generate_map(&game_map);


    initialize_game_values(&game_map);
    init_window();
    int s_continue = 1;//to realize should continue or no??
    while(s_continue) {
        render_clear();
        draw_shapes(&game_map);
        bullets_moving(&game_map);
        if (event_handling(&game_map) == EXIT) break;
        present_window();
    }
    quit_window();
    return 0;
}