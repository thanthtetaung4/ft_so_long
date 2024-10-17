/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:43:20 by taung             #+#    #+#             */
/*   Updated: 2024/10/18 01:44:03 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

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
