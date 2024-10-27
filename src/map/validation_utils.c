/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 00:44:07 by taung             #+#    #+#             */
/*   Updated: 2024/10/27 17:18:13 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**copy_map(t_map *map_data)
{
	char	**map_copy;
	int		i;

	map_copy = (char **)malloc(map_data->rows * sizeof(char *));
	i = 0;
	while (i < map_data->rows)
	{
		map_copy[i] = ft_strdup(map_data->map[i]);
		if (!map_copy[i])
		{
			while (--i >= 0)
				free(map_copy[i]);
			free(map_copy);
			return (NULL);
		}
		i++;
	}
	return (map_copy);
}

void	free_map_copy(char **map_copy, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}

t_Position	find_player_start(t_map *map_data)
{
	t_Position	player_pos;
	int			i;
	int			j;

	player_pos.x = -1;
	player_pos.y = -1;
	i = 0;
	while (i < map_data->rows)
	{
		j = 0;
		while (j < map_data->cols)
		{
			if (map_data->map[i][j] == 'P')
			{
				player_pos.x = i;
				player_pos.y = j;
				return (player_pos);
			}
			j++;
		}
		i++;
	}
	return (player_pos);
}

int	flood_fill(t_fill_info *info, t_Position pos, int rows, int cols)
{
	t_Position	directions[4];
	int			i;

	if (pos.x < 0 || pos.x >= rows || pos.y < 0 || pos.y >= cols)
		return (0);
	if (info->map[pos.x][pos.y] == '1' || info->map[pos.x][pos.y] == 'F')
		return (0);
	if (info->map[pos.x][pos.y] == 'C')
		info->collected++;
	if (info->map[pos.x][pos.y] == 'E'
		&& info->collected == info->total_collectable)
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
	return (1);
}

void	count_components(t_map *map_data, t_Position *player_start,
		int *exits, int *players)
{
	int	i;
	int	j;

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
