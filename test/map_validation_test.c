#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char    **map;
    int     rows;
    int     cols;
    int     collectables;
} s_map;

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    char    **map;
    int     collected;
    int     found_exit;
} t_fill_info;

// Function to copy the map
char **copy_map(s_map *map_data) {
    char **map_copy;
    int i;

    map_copy = (char **)malloc(map_data->rows * sizeof(char *));
    i = 0;
    while (i < map_data->rows) {
        map_copy[i] = strdup(map_data->map[i]);
        if (!map_copy[i]) {
            while (--i >= 0) free(map_copy[i]);
            free(map_copy);
            return NULL;
        }
        i++;
    }
    return map_copy;
}

// Function to free the map copy
void free_map_copy(char **map_copy, int rows) {
    int i = 0;
    while (i < rows) {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);
}

// Function to find the player's start position
Position find_player_start(s_map *map_data) {
    Position player_pos;
    int i;
    int j;

    player_pos.x = -1;
    player_pos.y = -1;
    i = 0;
    while (i < map_data->rows) {
        j = 0;
        while (j < map_data->cols) {
            if (map_data->map[i][j] == 'P') {
                player_pos.x = i;
                player_pos.y = j;
                return player_pos;
            }
            j++;
        }
        i++;
    }
    return player_pos;
}

// Flood fill using the fill info struct
int flood_fill(t_fill_info *info, Position pos, int rows, int cols)
{
	Position directions[4];
	int i;

	if (pos.x < 0 || pos.x >= rows || pos.y < 0 || pos.y >= cols)
		return 0;
	if (info->map[pos.x][pos.y] == '1' || info->map[pos.x][pos.y] == 'F')
		return 0;
	if (info->map[pos.x][pos.y] == 'C')
		info->collected++;
	if (info->map[pos.x][pos.y] == 'E')
		info->found_exit++;
	info->map[pos.x][pos.y] = 'F';
	directions[0].x = pos.x + 1;
	directions[0].y = pos.y;
	directions[1].x = pos.x - 1;
	directions[1].y = pos.y;
	directions[2].x = pos.x;
	directions[2].y = pos.y + 1;
	directions[3].x = pos.x;
	directions[3].y = pos.y - 1;
	i = -1;
	while (++i < 4)
		flood_fill(info, directions[i], rows, cols);
	return 1;
}

// Function to check if there's a valid path using the map copy and fill info
int check_valid_path(s_map *map_data, Position player_start) {
    t_fill_info fill_info;
    char **map_copy;

    map_copy = copy_map(map_data);
    if (!map_copy) {
        printf("Error\nMemory allocation failed.\n");
        return 0;
    }

    fill_info.map = map_copy;
    fill_info.collected = 0;
    fill_info.found_exit = 0;

    flood_fill(&fill_info, player_start, map_data->rows, map_data->cols);

    free_map_copy(map_copy, map_data->rows);

    if (fill_info.collected != map_data->collectables || fill_info.found_exit != 1) {
        printf("Error\nNo valid path.\n");
        return 0;
    }
    return 1;
}

// Function to check if the map is rectangular
int is_rectangular(s_map *map_data) {
    int i;
    int len;

    i = 1;
    len = strlen(map_data->map[0]);
    while (i < map_data->rows) {
        if (strlen(map_data->map[i]) != len) {
            printf("Error\nMap must be rectangular.\n");
            return 0;
        }
        i++;
    }
    return 1;
}

// Function to check if the map is surrounded by walls
int is_surrounded_by_walls(s_map *map_data) {
    int i;
    int j;

    i = 0;
    while (i < map_data->cols) {
        if (map_data->map[0][i] != '1' || map_data->map[map_data->rows - 1][i] != '1') {
            printf("Error\nMap must be surrounded by walls.\n");
            return 0;
        }
        i++;
    }

    j = 0;
    while (j < map_data->rows) {
        if (map_data->map[j][0] != '1' || map_data->map[j][map_data->cols - 1] != '1') {
            printf("Error\nMap must be surrounded by walls.\n");
            return 0;
        }
        j++;
    }
    return 1;
}


// Function to count exits, players, and collectables
void count_components(s_map *map_data, Position *player_start, int *exits, int *players)
{
	int i, j;

	i = 0;
	while (i < map_data->rows)
	{
		j = 0;
		while (j < map_data->cols)
		{
			if (map_data->map[i][j] == 'E')
				(*exits)++;
			if (map_data->map[i][j] == 'P')
			{
				(*players)++;
				player_start->x = i;
				player_start->y = j;
			}
			if (map_data->map[i][j] == 'C')
				map_data->collectables++;
			j++;
		}
		i++;
	}
}

int check_map_components(s_map *map_data, Position *player_start)
{
	int exits;
	int players;

	exits = 0;
	players = 0;
	map_data->collectables = 0;

	// Call the helper function to count components
	count_components(map_data, player_start, &exits, &players);

	if (exits != 1 || players != 1 || map_data->collectables < 1)
	{
		printf("Error\nInvalid map configuration.\n");
		return 0;
	}
	return 1;
}


// Main validation function
int validate_map(s_map *map_data) {
    Position player_start;

    if (!is_rectangular(map_data)) return 0;
    if (!is_surrounded_by_walls(map_data)) return 0;
    if (!check_map_components(map_data, &player_start)) return 0;
    if (!check_valid_path(map_data, player_start)) return 0;

    return 1;
}

int main() {
    // Example map for testing
    char *map[] = {
        strdup("111111111"),
        strdup("1P0C01C11"),
        strdup("1010000E1"),
        strdup("111111111")
    };

    s_map map_data;
    map_data.map = map;
    map_data.rows = 4;
    map_data.cols = strlen(map[0]);

    if (validate_map(&map_data)) {
        printf("Map is valid!\n");
    } else {
        printf("Map is invalid!\n");
    }

    // Free dynamically allocated memory for map
    int i = 0;
    while (i < map_data.rows) {
        free(map_data.map[i]);
        i++;
    }

    return 0;
}
