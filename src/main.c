/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:01:31 by taung             #+#    #+#             */
/*   Updated: 2024/10/25 16:58:42 by taung            ###   ########.fr       */
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
		if (!map)
			return (1);
		data.map = *(map);
		free(map);
		init_player(&data);
		init_mlx(&data, &data.map);
		initail_render_img(&data);
		render_img(&data);
		mlx_render(&data);
		free_all(&data);
		return (0);
	}
	else
	{
		ft_putstr_fd("\033[31;1mError\nUsage: ./so_long <valid_path>\033[0m\n", 1);
		return (1);
	}
}
