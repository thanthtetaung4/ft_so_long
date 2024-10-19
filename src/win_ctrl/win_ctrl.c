/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_ctrl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 01:46:33 by taung             #+#    #+#             */
/*   Updated: 2024/10/19 22:58:31 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	close_win(t_data *data)
{
	if (data->mlx && data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		// free(data->mlx);
		ft_putstr_fd("GAME OVER!\n",1);
		exit(0);
	}
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	printf("player is at x:%d,y:%d, point: %d\n",data->player.p_x,data->player.p_y,data->player.points);
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
		exit(0);
	}
	else
	{
		if (keysym == XK_w)
		{
			ft_putchar_fd('w',1);
			// data->p_y-=20;
			move_player(data,0,-1);
		}
		else if (keysym == XK_a)
		{
			ft_putchar_fd('a',1);
			move_player(data,-1,0);

		}
		else if (keysym == XK_s)
		{
			ft_putchar_fd('s',1);
			move_player(data,0,1);

		}
		else if (keysym == XK_d)
		{
			ft_putchar_fd('d',1);
			move_player(data,1,0);
		}
		else
			ft_putstr_fd("try pressing wasd!",1);
		ft_putchar_fd('\n',1);
	}
	return (0);
}

// int	render_img(t_data *data)
// {
// 	for (size_t i = 0; i < data->win_width; i += data->images[0].width)
// 	{
// 		for (size_t j = 0; j < data->win_height; j+=data->images[0].height)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[1].mlx_img, i, j);
// 		}
// 	}
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->images[0].mlx_img, data->p_x, data->p_y);
// }
