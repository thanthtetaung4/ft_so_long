/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:46:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/17 16:54:23 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	close_win(s_mlx *mlx_data)
{
	if (mlx_data->mlx && mlx_data->win)
	{
		mlx_destroy_window(mlx_data->mlx, mlx_data->win);
		mlx_destroy_display(mlx_data->mlx);
		free(mlx_data->mlx);
		ft_putstr_fd("GAME OVER!\n",1);
		exit(0);
	}
	return (0);
}

int	handle_keypress(int keysym, s_mlx *mlx_data)
{
	if (keysym == XK_Escape)
		close_win(mlx_data);
	else
	{
		if (keysym == XK_w)
			ft_putchar_fd('w',1);
		else if (keysym == XK_a)
			ft_putchar_fd('a',1);
		else if (keysym == XK_s)
			ft_putchar_fd('s',1);
		else if (keysym == XK_d)
			ft_putchar_fd('d',1);
		else
			ft_putstr_fd("try pressing wasd!",1);
		ft_putchar_fd('\n',1);
	}
	return (0);
}
