/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:34:22 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 17:10:27 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	get_pos_from_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			if (data->map.map[i][j] == 'P')
			{
				data->player.p_x = j;
				data->player.p_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player(t_data *data)
{
	t_player	player;

	player.win = 0;
	player.points = 0;
	data->player = player;
	get_pos_from_map(data);
}

void	move_player(t_data *data, int x, int y)
{
	if (is_valid_move(data, x, y))
	{
		data->player.p_x += x;
		data->player.p_y += y;
		data->move_counter++;
		ft_putstr_fd("MOVE COUNTER : ", 1);
		ft_putnbr_fd(data->move_counter, 1);
		ft_putstr_fd("\n", 1);
		if (is_collectable(data, data->player.p_x, data->player.p_y))
		{
			data->player.points++;
			update_map(data, data->player.p_x, data->player.p_y, '0');
		}
		if (is_exit(data, data->player.p_x, data->player.p_y))
		{
			if (data->map.collectables == data->player.points)
				win(data);
		}
	}
}

t_Position	find_player_pos(t_data *data)
{
	int			i;
	int			j;
	t_Position	pos;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			if (data->map.map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
			}
			j++;
		}
		i++;
	}
	return (pos);
}
// cols == x & rows == y
