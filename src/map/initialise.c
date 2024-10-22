/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:10 by taung             #+#    #+#             */
/*   Updated: 2024/10/22 19:01:07 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map	*parse_map_err(char *str, t_map *map)
{
	free(str);
	free_map(map);
	free(map);
	return (NULL);
}

t_map	*parse_map(const char *path)
{
	int		fd;
	char	*res;
	t_map	*map;
	int		rows;

	map = NULL;
	rows = 0;
	map = alloc_map(map, count_row(path));
	fd = open(path, O_RDONLY);
	res = get_next_line(fd);
	if (!res)
		return (parse_map_err(res, map));
	map->cols = ft_strlen(res) - 1;
	while (res)
	{
		ft_map_row_cp(&map->map[rows], res);
		free(res);
		res = NULL;
		rows++;
		res = get_next_line(fd);
	}
	close(fd);
	map->rows = rows;
	free(res);
	return (map);
}

int	validate_map(t_map *map_data)
{
	t_Position	player_start;

	if (!is_rectangular(map_data))
		return (0);
	if (!entity_check(map_data))
		return (0);
	if (!is_surrounded_by_walls(map_data))
		return (0);
	if (!check_map_components(map_data, &player_start))
		return (0);
	if (!check_valid_path(map_data, player_start))
		return (0);
	return (1);
}

t_map	*init_map(const char *path)
{
	t_map	*map;

	if (!(path_check(path)))
	{
		return (NULL);
	}
	map = parse_map(path);
	if (map == NULL)
	{
		ft_putstr_fd("Error Empty map || row < 3\n", 1);
		free(map);
		return (NULL);
	}
	if (validate_map(map))
		return (map);
	else
	{
		free_map(map);
		free(map);
		return (NULL);
	}
}
