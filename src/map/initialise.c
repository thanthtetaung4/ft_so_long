/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:10 by taung             #+#    #+#             */
/*   Updated: 2024/10/15 14:04:39 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include <fcntl.h>

int	count_row(const char *path)
{
	int		fd;
	char	*res;
	int		cols;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	res = get_next_line(fd);
	if (!res)
		return (0);
	cols = ft_strlen(res);
	while (res)
	{
		if (cols != ft_strlen(res))
			return (0);
		i++;
		res = get_next_line(fd);
	}
	close(fd);
	return (i);
}
s_map	*alloc_map(s_map *map, int rows)
{
	map = malloc(sizeof(s_map));
	if (!map)
		return (NULL);
	map->map = malloc(sizeof(char *) * rows);
	if (!map->map)
		return (NULL);
	return (map);
}
void	ft_map_row_cp(char **dest, char *src)
{
	*dest = malloc(ft_strlen(src) + 1);
	if (!dest)
		return ;
	ft_strlcpy(*dest, (const char *)src, ft_strlen(src));
}
s_map	*parse_map(const char *path)
{
	int		fd;
	char	*res;
	s_map	*map;
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
		if (cols != ft_strlen(res))
			return (NULL);
		ft_map_row_cp(&map->map[rows], res);
		rows++;
		res = get_next_line(fd);
	}
	close(fd);
	map->cols = --cols;
	map->rows = rows;
	return (map);
}
s_map	*init_map(const char *path)
{
	s_map	*map;

	map = parse_map(path);
	/* map validation happens here! */
	return (map);
}
