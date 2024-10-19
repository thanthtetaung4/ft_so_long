/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:00:56 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 02:50:02 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_collectable(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'C')
		return 1;
	return 0;
}

int	is_exit(t_data *data, int x, int y)
{
	if (data->map.map[y][x] == 'E')
		return 1;
	return 0;
}

int	is_valid_move(t_data *data, int x, int y)
{
	if (data->player.p_y + y > 0 && data->player.p_y + y < data->map.rows
		&& data->player.p_x + x > 0 && data->player.p_x + x < data->map.cols)
	{
		if (data->map.map[data->player.p_y + y][data->player.p_x + x] != '1')
			return 1;
	}
	return 0;
}
