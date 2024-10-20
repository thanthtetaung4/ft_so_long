/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:01:31 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 16:02:56 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	*map;

	if (argc == 2)
	{
		data.move_counter = 0;
		map = (init_map(argv[1]));
		data.map = *(map);
		free(map);
		if (!(data.map.map))
			return (1);
		init_player(&data);
		init_mlx(&data, &data.map);
		render_img(&data);
		mlx_loop_hook(data.mlx, &render_img, &data);
		mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
		mlx_hook(data.mlx_win, DestroyNotify,
			StructureNotifyMask, &close_win, &data);
		mlx_loop(data.mlx);
		free_all(&data);
		return (0);
	}
	else
		return (1);
}
