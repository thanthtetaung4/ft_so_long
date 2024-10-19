/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:43:17 by taung             #+#    #+#             */
/*   Updated: 2024/10/19 22:42:22 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	calc_win_dimensions (t_map *map, t_data *data)
{
	data->win_height = map->rows * IMAGE_SIZE;
	data->win_width = map->cols * IMAGE_SIZE;
}

void	init_mlx(t_data *data, t_map *map)
{
	data->mlx = mlx_init();
	calc_win_dimensions(map, data);
	data->mlx_win = mlx_new_window(data->mlx, data->win_width, data->win_height, "so_long");
	data->map = *map;
	ft_print_map(&data->map);
	init_img(data);
}

void	parse_chars(t_data *data, int i, int j)
{
	int	x;
	int	y;

	x = j * IMAGE_SIZE;
	y = i * IMAGE_SIZE;

	// printf("map[0][0] : %d\n",data->map.map[0][0] == '1');
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->images[2].mlx_img, x,y);
	else if (data->map.map[i][j] == 'E')
	{
		if (data->player.points == data->map.collectables)
			mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->images[4].mlx_img, x,y);
		else
			mlx_put_image_to_window(data->mlx, data->mlx_win,
			data->images[1].mlx_img, x,y);
	}
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->images[3].mlx_img, x,y);
	else
		mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->images[1].mlx_img, x,y);
}

void	render_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win,
		data->images[0].mlx_img, data->player.p_x * IMAGE_SIZE,data->player.p_y * IMAGE_SIZE);
}

