/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 01:31:02 by taung             #+#    #+#             */
/*   Updated: 2024/10/28 01:46:13 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

t_Position	get_exit_pos(char **map, int rows, int cols)
{
	int			i;
	int			j;
	t_Position	pos;

	pos.x = 0;
	pos.y = 0;
	i = 0;
	while(i < rows)
	{
		j = 0;
		while(j < cols)
		{
			if(map[i][j] == 'E')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int	exit_ok(char **map, int rows, int cols)
{
	t_Position	exit_pos;

	exit_pos = get_exit_pos(map, rows, cols);
	if(map[exit_pos.y][exit_pos.x - 1] == 'F'
		|| map[exit_pos.y][exit_pos.x + 1] == 'F'
		|| map[exit_pos.y - 1][exit_pos.x] == 'F'
		|| map[exit_pos.y + 1][exit_pos.x] == 'F')
		return (1);
	return (0);
}
