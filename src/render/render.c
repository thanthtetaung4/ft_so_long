/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:33:48 by taung             #+#    #+#             */
/*   Updated: 2024/10/27 15:57:34 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	initail_render_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->mlx_win)
		return (1);
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			parse_chars(data, i, j);
			render_player(data);
			j++;
		}
		i++;
	}
	return (0);
}

int	render_img(t_data *data)
{
	int			i;
	int			j;
	t_Position	pos;

	i = 0;
	if (!data->mlx_win)
		return (1);
	pos = find_player_pos(data);
	if (pos.x != data->player.p_x || pos.y != data->player.p_y)
	{
		update_map(data, pos.x, pos.y, '0');
		update_map(data, data->player.p_x, data->player.p_y, 'P');
		while (i < data->map.rows)
		{
			j = 0;
			while (j < data->map.cols)
			{
				render_grass(data, i, j);
				render_player(data);
				j++;
			}
			i++;
		}
	}
	return (0);
}

void	mlx_render(t_data *data)
{
	mlx_loop_hook(data->mlx, &render_img, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &handle_keypress, data);
	mlx_hook(data->mlx_win, DestroyNotify,
		StructureNotifyMask, &close_win, data);
	mlx_loop(data->mlx);
}
