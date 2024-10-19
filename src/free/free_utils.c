/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 23:30:15 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 02:50:23 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_img(t_data	*data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (data->images[i].mlx_img)
		{
			mlx_destroy_image(data->mlx, data->images[i].mlx_img);
			data->images[i].mlx_img = NULL;
		}
		i++;
	}
}

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map.map)
	{
		while (i < data->map.rows)
		{
			free(data->map.map[i]);
			i++;
		}
		free(data->map.map);
		data->map.map = NULL;
	}
}

void	free_mlx(t_data *data)
{
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		data->mlx = NULL;
	}
}

void	free_all(t_data *data)
{
	free_img(data);
	free_map(data);
	free_mlx(data);
}
