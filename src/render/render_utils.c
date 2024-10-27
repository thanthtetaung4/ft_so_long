/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:43:17 by taung             #+#    #+#             */
/*   Updated: 2024/10/27 14:37:07 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	calc_win_dimensions(t_map *map, t_data *data)
{
	data->win_height = map->rows * IMAGE_SIZE;
	data->win_width = map->cols * IMAGE_SIZE;
}

void	init_mlx(t_data *data, t_map *map)
{
	data->mlx = mlx_init();
	calc_win_dimensions(map, data);
	data->map = *map;
	init_img(data);
	data->mlx_win = mlx_new_window(data->mlx,
			data->win_width, data->win_height, "so_long");
}

void	parse_chars(t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = j * IMAGE_SIZE;
	y = i * IMAGE_SIZE;
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->images[2].mlx_img, x, y);
	else if (data->map.map[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->images[4].mlx_img, x, y);
	}
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->images[3].mlx_img, x, y);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->images[1].mlx_img, x, y);
}

void	render_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->images[0].mlx_img, data->player.p_x * IMAGE_SIZE,
		data->player.p_y * IMAGE_SIZE);
}

void	render_grass(t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = j * IMAGE_SIZE;
	y = i * IMAGE_SIZE;
	if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->images[1].mlx_img, x, y);
}
