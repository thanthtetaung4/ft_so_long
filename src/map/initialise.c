/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:10 by taung             #+#    #+#             */
/*   Updated: 2024/10/19 03:33:54 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_map	*parse_map(const char *path)
{
	int		fd;
	char	*res;
	t_map	*map;
	int		rows;
	int		cols;

	rows = 0;
	map = alloc_map(map, count_row(path));
	fd = open(path, O_RDONLY);
	res = get_next_line(fd);
	if (!res)
		return (NULL);
	cols = ft_strlen(res);
	while (res)
	{
		ft_map_row_cp(&map->map[rows], res);
		rows++;
		res = get_next_line(fd);
	}
	close(fd);
	map->cols = --cols;
	map->rows = rows;
	return (map);
}
// Main validation function
int validate_map(t_map *map_data)
{
	Position player_start;
	if (!entity_check(map_data))
		return 0;
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
t_map	*init_map(const char *path)
{
	t_map	*map;

	map = parse_map(path);
	if (!(path_check(path)))
		return NULL;
	if (validate_map(map))
	{
		printf("MAP is VALID!!\n");
		printf("MAP is\n");
		ft_print_map(map);
		return (map);
	}
	else
		return (NULL);
}
