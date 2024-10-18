/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:33:48 by taung             #+#    #+#             */
/*   Updated: 2024/10/19 05:31:38 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../so_long.h"

int	render_img(t_data *data)
{
	for (size_t i = 0; i < data->map.rows; i++)
	{
		for (size_t j = 0; j < data->map.cols; j++)
		{
			parse_chars(data,i,j);
		// 	mlx_put_image_to_window(data->mlx, data->mlx_win,
		// data->images[2].mlx_img, i, j);
		}
	}
	// mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[0].mlx_img, data->p_x, data->p_y);
}
