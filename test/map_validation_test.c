#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WALL '1'
#define EMPTY '0'
#define COLLECTABLE 'C'
#define EXIT 'E'
#define PLAYER 'P'

typedef struct {
    int x, y;
} Position;

int flood_fill(char **map, int width, int height, Position player, int *collectables, int *exits) {
    // Base conditions
    if (player.x < 0 || player.x >= height || player.y < 0 || player.y >= width)
        return 0;  // Out of bounds

    if (map[player.x][player.y] == WALL)
        return 0;  // Hit a wall

    // If the player is on a collectable, increment collectable count
    if (map[player.x][player.y] == COLLECTABLE)
        (*collectables)++;

    // If the player is on the exit, increment exit count
    if (map[player.x][player.y] == EXIT)
        (*exits)++;

    // Mark the current position as visited by replacing it with a wall
    map[player.x][player.y] = WALL;

    // Recursive exploration in four directions
    Position directions[] = {
        {player.x + 1, player.y},  // Down
        {player.x - 1, player.y},  // Up
        {player.x, player.y + 1},  // Right
        {player.x, player.y - 1}   // Left
    };

    for (int i = 0; i < 4; i++) {
        flood_fill(map, width, height, directions[i], collectables, exits);
    }

    return 1;
}

int check_map(char **map, int width, int height, Position player) {
    int collectables = 0;
    int exits = 0;
    int total_collectables = 0;

    // Count the total number of collectables on the map
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map[i][j] == COLLECTABLE)
                total_collectables++;
        }
    }

    // Perform flood fill to check the map
    flood_fill(map, width, height, player, &collectables, &exits);

    // Check if all collectables are collected and exactly one exit is reachable
    if (collectables == total_collectables && exits == 1) {
        return 1;  // Valid map
    }

    return 0;  // Invalid map
}

int main() {
    // Dynamic map allocation (modifiable)
    char *map[] = {
        strdup("1111111111111111111111111111111111"),
        strdup("1E00000000000000C00000C00000000001"),
        strdup("1010010100100000101001001110010101"),
        strdup("1P0000000C00C000000000001C10000001"),
        strdup("1111111111111111111111111111111111")
    };//This is not a valid map the program needs to be improved

    Position player = {3, 1};  // Starting position of the player (P)

    if (check_map(map, 5, 5, player)) {
        printf("Map is valid!\n");
    } else {
        printf("Map is invalid!\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < 5; i++) {
        free(map[i]);
    }

    return 0;
}
