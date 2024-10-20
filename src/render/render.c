/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:33:48 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 15:38:48 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	render_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (!data->mlx_win)
		return (1);
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			parse_chars(data, i, j);
			render_player(data);
			j++;
		}
		i++;
	}
	return (0);
}
