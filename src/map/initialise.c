/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 20:54:10 by taung             #+#    #+#             */
/*   Updated: 2024/10/14 22:27:26 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"
#include<fcntl.h>

s_map *parse_map(const char path)
{
	int		fd;
	char	*res;
	s_map	*map;
	int		i;
	int		side_len;

	i = 0;
	fd = open(path, O_RDONLY);
	res = get_next_line(fd);
	if(!res)
		return NULL;
	side_len = ft_strlen(res);
	while(res)
	{
		printf("%s",res);
		if (side_len != ft_strlen(res))
			return NULL;
		map->map[i] = res;
		i++;
		res = get_next_line(fd);
	}
	close(fd);
	map->cols = side_len;
	map->rows = i;
	return (map);
}
s_map *init_map(const char *path)
{
	s_map	*map;

	map = parse_map(path);
	/* map validation happens here! */

	return map;
}
