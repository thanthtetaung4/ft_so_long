/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42singapore.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 21:34:30 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 03:22:12 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	win(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	data->mlx_win = NULL;
	ft_putstr_fd("YOU WIN!!\n", 1);
}
