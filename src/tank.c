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
    initialize_game_values(&game_map);
    init_window();
//    draw_background();
    while(1) {
        render_clear();
        if (game_map.game_pause == 0) {
            draw_shapes(&game_map);
            bullets_moving(&game_map);
        } else {
            if (game_map.first_menu) {
                draw_first_menu();
            } else {
                draw_shapes(&game_map);
                draw_game_menu();
            }
        }
        if (event_handling(&game_map) == EXIT) break;
        if (game_map.game_pause == 0) {
            game_map.frames++;
            if (game_map.frames % 400 == 0) {
                set_a_powerup(&game_map);
            }
        }
        present_window();
    }
    quit_window();
    return 0;
}