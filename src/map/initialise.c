/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:10 by taung             #+#    #+#             */
/*   Updated: 2024/10/26 18:23:14 by taung            ###   ########.fr       */
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

void	parse_map_helper(t_map *map, char *res)
{
	if ((int)ft_strlen(res) > 1)
	{
		ft_map_row_cp(&map->map[map->rows], res);
		map->cols = ft_strlen(res) - 1;
		map->rows++;
	}
}

t_map	*parse_map(const char *path)
{
	int		fd;
	char	*res;
	t_map	*map;

	map = NULL;
	map = alloc_map(map, count_row(path));
	fd = open(path, O_RDONLY);
	map->rows = 0;
	res = get_next_line(fd);
	if (!res)
		return (parse_map_err(res, map));
	while (res)
	{
		parse_map_helper(map, res);
		free(res);
		res = NULL;
		res = get_next_line(fd);
	}
	close(fd);
	free(res);
	return (map);
}

int	validate_map(t_map *map_data)
{
	t_Position	player_start;

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
