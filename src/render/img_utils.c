/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 03:37:35 by taung             #+#    #+#             */
/*   Updated: 2024/10/19 04:23:41 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	init_img(t_data *data)
{
	data->images[0].mlx_img = mlx_xpm_file_to_image(data->mlx, CAT_IMG, &(data->images[0].width), &(data->images[0].height));
	data->images[1].mlx_img = mlx_xpm_file_to_image(data->mlx, PATH_IMG, &(data->images[1].width), &(data->images[1].height));
	data->images[2].mlx_img = mlx_xpm_file_to_image(data->mlx, WALL_IMG, &(data->images[2].width), &(data->images[2].height));
	data->images[3].mlx_img = mlx_xpm_file_to_image(data->mlx, FISH_IMG, &(data->images[3].width), &(data->images[3].height));
	data->images[4].mlx_img = mlx_xpm_file_to_image(data->mlx, EXIT_IMG, &(data->images[4].width), &(data->images[4].height));

	printf("img[1] width %d and height %d\n",data->images[1].width,data->images[1].width);
}
