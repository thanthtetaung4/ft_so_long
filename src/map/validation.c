/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:55:20 by taung             #+#    #+#             */
/*   Updated: 2024/10/18 01:20:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Function to check if there's a valid path using the map copy and fill info
int check_valid_path(s_map *map_data, Position player_start)
{
	t_fill_info fill_info;
	char **map_copy;

	map_copy = copy_map(map_data);
	if (!map_copy)
	{
		ft_putstr_fd("Error\nMemory allocation failed.\n",1);
		return 0;
	}

	fill_info.map = map_copy;
	fill_info.collected = 0;
	fill_info.found_exit = 0;

	flood_fill(&fill_info, player_start, map_data->rows, map_data->cols);

	free_map_copy(map_copy, map_data->rows);

	if (fill_info.collected != map_data->collectables || fill_info.found_exit != 1)
	{
		ft_putstr_fd("Error\nNo valid path.\n",1);
		return 0;
	}
	return 1;
}

// Function to check if the map is rectangular
int is_rectangular(s_map *map_data)
{
	int i;
	int len;

	i = 1;
	len = strlen(map_data->map[0]);
	while (i < map_data->rows)
	{
		if (strlen(map_data->map[i]) != len)
		{
			ft_putstr_fd("Error\nMap must be rectangular.\n",1);
			return 0;
		}
		i++;
	}
	return 1;
}

// Function to check if the map is surrounded by walls
int is_surrounded_by_walls(s_map *map_data)
{
	int i;
	int j;

	i = 0;
	while (i < map_data->cols)
	{
		if (map_data->map[0][i] != '1' || map_data->map[map_data->rows - 1][i] != '1')
		{
			ft_putstr_fd("Error\nMap must be surrounded by walls.\n",1);
			return 0;
		}
		i++;
	}
	j = 0;
	while (j < map_data->rows)
	{
		if (map_data->map[j][0] != '1' || map_data->map[j][map_data->cols - 1] != '1')
		{
			ft_putstr_fd("Error\nMap must be surrounded by walls.\n",1);
			return 0;
		}
		j++;
	}
	return 1;
}

// Function to count exits, players, and collectables
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
		ft_putstr_fd("Error\nInvalid map configuration.\n",1);
		return 0;
	}
	return 1;
}

// Main validation function
int validate_map(s_map *map_data)
{
	Position player_start;

	if (!is_rectangular(map_data))
		return 0;
	if (!is_surrounded_by_walls(map_data))
		return 0;
	if (!check_map_components(map_data, &player_start))
		return 0;
	if (!check_valid_path(map_data, player_start))
		return 0;

	return 1;
}
// int main() {
//     // Example map for testing
//     char *map[] = {
//         strdup("111111111"),
//         strdup("1P0C01C11"),
//         strdup("1010000E1"),
//         strdup("111111111")
//     };

//     s_map map_data;
//     map_data.map = map;
//     map_data.rows = 4;
//     map_data.cols = strlen(map[0]);

//     if (validate_map(&map_data)) {
//         printf("Map is valid!\n");
//     } else {
//         printf("Map is invalid!\n");
//     }

//     // Free dynamically allocated memory for map
//     int i = 0;
//     while (i < map_data.rows) {
//         free(map_data.map[i]);
//         i++;
//     }

//     return 0;
// }
