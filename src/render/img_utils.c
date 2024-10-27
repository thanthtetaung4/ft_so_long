/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 03:37:35 by taung             #+#    #+#             */
/*   Updated: 2024/10/27 13:52:06 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_img(t_data *data)
{
	int	i;

	data->images[0].mlx_img = mlx_xpm_file_to_image(data->mlx,
			CAT_IMG, &(data->images[0].width), &(data->images[0].height));
	data->images[1].mlx_img = mlx_xpm_file_to_image(data->mlx,
			PATH_IMG, &(data->images[1].width), &(data->images[1].height));
	data->images[2].mlx_img = mlx_xpm_file_to_image(data->mlx,
			WALL_IMG, &(data->images[2].width), &(data->images[2].height));
	data->images[3].mlx_img = mlx_xpm_file_to_image(data->mlx,
			FISH_IMG, &(data->images[3].width), &(data->images[3].height));
	data->images[4].mlx_img = mlx_xpm_file_to_image(data->mlx,
			EXIT_IMG, &(data->images[4].width), &(data->images[4].height));
	i = 0;
	while (i < 5)
	{
		if (data->images[i].mlx_img == NULL)
		{
			free_all(data);
			ft_putstr_fd("\033[0;31m", 1);
			ft_putstr_fd("FATAL ERROR\nTextures not found\n", 2);
			ft_putstr_fd("\033[0m", 1);
			exit(0);
		}
		i++;
	}
}
