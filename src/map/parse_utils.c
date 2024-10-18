/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 01:43:20 by taung             #+#    #+#             */
/*   Updated: 2024/10/19 03:52:58 by taung            ###   ########.fr       */
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
	if (fd == -1)
	{
		ft_putstr_fd("INVALID PATH\n",2);
		return 0;
	}
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
t_map	*alloc_map(t_map *map, int rows)
{
	map = malloc(sizeof(t_map));
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
int	path_check(const char *path)
{
	if (*(ft_strrchr(path,'.')) == path[ft_strlen(path) - 4] &&
		*(ft_strrchr(path,'b')) == path[ft_strlen(path) - 3] &&
		*(ft_strrchr(path,'e')) == path[ft_strlen(path) - 2] &&
		*(ft_strrchr(path,'r')) == path[ft_strlen(path) - 1])
	{
		if(open(path, O_RDONLY) > -1)
			return (1);
	}
	ft_putstr_fd("\033[31;1mPath KO :(\033[0m\n",2);
	return (0);
}

// int main()
// {
// 	char *path = "map.ber";
// 	if (path_check(path))
// 	{
// 		printf("PATH OK");
// 	}

// }
