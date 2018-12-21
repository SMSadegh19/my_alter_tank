//
// Created by sadegh on 12/20/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "structs.h"
#include "view.h"
#include "physics.h"
#include "logic.h"

int vertex[12][7] = {};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int exist_0_vertex() {
    int exist = 0;
    for (int i = 1; i < 11; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (vertex[i][j] == 0) {
                exist = 1;
                break;
            }
        }
        if (exist) {
            break;
        }
    }
    return exist;
}

void generate_map(Map *map) {
    srand((unsigned int)(time(NULL)));
    map->number_of_walls = 0;
    for (int i = 0; i < 12; i += 11) {
        for (int j = 0; j < 7; j++) {
            vertex[i][j] = 1;
        }
    }
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 7; j += 6) {
            vertex[i][j] = 1;
        }
    }
    //around_walls
    ///*****
    map->walls[0].x1 = 0; map->walls[0].y1 = 0; map->walls[0].x2 = 11; map->walls[0].y2 = 0;
    map->walls[1].x1 = 11; map->walls[1].y1 = 0; map->walls[1].x2 = 11; map->walls[1].y2 = 6;
    map->walls[2].x1 = 11; map->walls[2].y1 = 6; map->walls[2].x2 = 0; map->walls[2].y2 = 6;
    map->walls[3].x1 = 0; map->walls[3].y1 = 6; map->walls[3].x2 = 0; map->walls[3].y2 = 0;
    map->number_of_walls = 4;
    ///*****
    //around walls
//    if (!(rand() % 3)) {
//        map->walls[map->number_of_walls].x1 = 1; map->walls[map->number_of_walls].y1 = 0; map->walls[map->number_of_walls].x2 = 1; map->walls[map->number_of_walls].y2 = 1;
//        map->number_of_walls++;
//        vertex[1][1] = 1;
//    }
    int i, j;
    while (exist_0_vertex()) {
        for (i = 0; i < 12; i++) {
            for (j = 0; j < 7; ++j) {
                while (1) {
                    int number_of_ways = 0;
                    int is_ok_to_go[4] = {};
                    int warn_to_go[4] = {};
                    for (int k = 0; k < 4; ++k) {
                        if (j == 0) {
                            warn_to_go[1] = 1;
                        }
                        if (j == 6) {
                            warn_to_go[0] = 1;
                        }
                        if (i == 0) {
                            warn_to_go[3] = 1;
                        }
                        if (i == 11) {
                            warn_to_go[2] = 1;
                        }
                        if (warn_to_go[k] == 0 && !(vertex[i + dx[k]][j + dy[k]])) {
                            number_of_ways++;
                            is_ok_to_go[k] = 1;
                        }
                    }
                    if (!number_of_ways) {
                        break;
                    }
                    int k = rand() % 4;
                    while (!is_ok_to_go[k]) {
                        k = rand() % 4;
                    }
                    if (rand() % 3) {
                        map->walls[map->number_of_walls].x1 = i;
                        map->walls[map->number_of_walls].y1 = j;
                        map->walls[map->number_of_walls].x2 = i + dx[k];
                        map->walls[map->number_of_walls].y2 = j + dy[k];
                        map->number_of_walls++;
                        vertex[i][j] = 1;
                        vertex[i + dx[k]][j + dy[k]] = 1;
                    }
                    i += dx[k];
                    j += dy[k];
                }
            }
        }
    }

    //convert wall numbers to big one
    for (int k = 0; k < map->number_of_walls; ++k) {
        map->walls[k].x1 *= 100;
        map->walls[k].y1 *= 100;
        map->walls[k].x2 *= 100;
        map->walls[k].y2 *= 100;
        map->walls[k].x1 += 20;
        map->walls[k].y1 += 20;
        map->walls[k].x2 += 20;
        map->walls[k].y2 += 20;
    }
}