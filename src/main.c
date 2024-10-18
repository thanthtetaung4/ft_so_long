#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	*map;

	data.p_x = 0,data.p_y = 0;

	// mlx_data = malloc(sizeof(s_mlx));
	map = init_map(argv[1]);
	if (!map)
		return 1;
	init_mlx(&data, map);
	printf("win width %d height %d\n",data.win_width, data.win_height);

	mlx_loop_hook(data.mlx, &render_img, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &close_win, &data);
	mlx_loop(data.mlx);
}

// int	main(int argc, char **argv)
// {
// 	int			fd;
// 	const char	*path;
// 	s_map		*map;
// 	char		*res;

// 	map = init_map(argv[1]);
// 	if (map)
// 	{
// 		return 0;
// 	}

// 	// printf("%ld\n",ft_strlen(path));
// }
