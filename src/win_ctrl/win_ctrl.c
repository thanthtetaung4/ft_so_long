/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:46:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/17 02:47:01 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	close_win(int keycode, s_mlx *mlx_data)
{

		// mlx_destroy_window(mlx_data->mlx,mlx_data->win);
		// mlx_data->win = NULL;
		// mlx_data->mlx = NULL;
		/* code */

	if (mlx_data->mlx && mlx_data->win) // Check if both are valid before calling
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		// exit(1);
		// free(mlx_data->mlx);

	}
	else
		ft_printf("BAD PTRS\n");
	return (0);
}

int	handle_keypress(int keysym, s_mlx *mlx_data)
{
	ft_printf("%d\n",keysym);
	return (0);
}
