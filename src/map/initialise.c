/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:10 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 16:01:10 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
		return (NULL);
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
	Position	player_start;

	if (!entity_check(map_data))
		return (0);
	if (!is_rectangular(map_data))
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

	map = parse_map(path);
	if (!(path_check(path)))
		return (NULL);
	if (validate_map(map))
		return (map);
	else
		return (NULL);
}
