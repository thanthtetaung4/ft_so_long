/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:33:48 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 00:17:11 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../so_long.h"

int	render_img(t_data *data)
{
	if (!data->mlx_win)
		return 1;
	for (size_t i = 0; i < data->map.rows; i++)
	{
		for (size_t j = 0; j < data->map.cols; j++)
		{
			parse_chars(data,i,j);
			render_player(data);
		}
	}
	return 0;
}
