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
    FILE *myFile;
    myFile = fopen("mapmap.txt", "r");
    game_map.walls = malloc(sizeof(Wall) * 30);


    int number_of_walls;
//    int map_x1[3][30];
//    int map_y1[3][30];
//    int map_x2[3][30];
//    int map_y2[3][30];

    if (myFile == NULL){
        printf("Error Reading File\n");
        exit (0);
    }


    fscanf(myFile, "%d", &game_map.number_of_walls);
    for (int j = 0; j < game_map.number_of_walls; ++j) {
        fscanf(myFile, "%d", &game_map.walls[j].x1);
        fscanf(myFile, "%d", &game_map.walls[j].y1);
        fscanf(myFile, "%d", &game_map.walls[j].x2);
        fscanf(myFile, "%d", &game_map.walls[j].y2);
    }

//    for (int i = 0; i < 1; i++){
//        printf("%d\n", number_of_walls);
//        for (int j = 0; j < number_of_walls; ++j) {
//            printf("%d ", game_map.walls[j].x1);
//            printf("%d ", game_map.walls[j].y1);
//            printf("%d ", game_map.walls[j].x2);
//            printf("%d\n", game_map.walls[j].y2);
//        }
//    }

    fclose(myFile);

    ////
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