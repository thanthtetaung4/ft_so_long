/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:55:20 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 15:59:41 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	entity_check(t_map *map_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_data->rows)
	{
		j = 0;
		while (j < map_data->cols)
		{
			if (map_data->map[i][j] != WALL && map_data->map[i][j] != PLAYER
			&& map_data->map[i][j] != COLLECTABLE && map_data->map[i][j] != EXIT
			&& map_data->map[i][j] != EMPTY)
			{
				ft_putstr_fd("Error\nInvalid Char in the map data\n", 1);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_valid_path(t_map *map_data, Position player_start)
{
	t_fill_info	fill_info;
	char		**map_copy;

	map_copy = copy_map(map_data);
	if (!map_copy)
	{
		ft_putstr_fd("Error\nMemory allocation failed.\n", 1);
		return (0);
	}
	fill_info.map = map_copy;
	fill_info.collected = 0;
	fill_info.found_exit = 0;
	flood_fill(&fill_info, player_start, map_data->rows, map_data->cols);
	free_map_copy(map_copy, map_data->rows);
	if (fill_info.collected != map_data->collectables
		|| fill_info.found_exit != 1)
	{
		ft_putstr_fd("Error\nNo valid path.\n", 1);
		return (0);
	}
	return (1);
}

int	is_rectangular(t_map *map_data)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(map_data->map[0]);
	while (i < map_data->rows)
	{
		if (ft_strlen(map_data->map[i]) != len)
		{
			ft_putstr_fd("Error\nMap must be rectangular.\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	is_surrounded_by_walls(t_map *map_data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map_data->cols)
	{
		if (map_data->map[0][i] != '1'
			|| map_data->map[map_data->rows - 1][i] != '1')
		{
			ft_putstr_fd("Error\nMap must be surrounded by walls.\n", 1);
			return (0);
		}
	}
	j = 0;
	while (j < map_data->rows)
	{
		if (map_data->map[j][0] != '1'
		|| map_data->map[j][map_data->cols - 1] != '1')
		{
			ft_putstr_fd("Error\nMap must be surrounded by walls.\n", 1);
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_map_components(t_map *map_data, Position *player_start)
{
	int	exits;
	int	players;

	exits = 0;
	players = 0;
	map_data->collectables = 0;
	count_components(map_data, player_start, &exits, &players);
	if (exits != 1 || players != 1 || map_data->collectables < 1)
	{
		ft_putstr_fd("Error\nInvalid map configuration.\n", 1);
		return (0);
	}
	return (1);
}
