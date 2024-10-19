#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	*map;


	// mlx_data = malloc(sizeof(s_mlx));
	data.map = *(init_map(argv[1]));
	if (!(data.map.map))
		return 1;
	init_player(&data);
	// ft_print_map(&data.map);
	// printf("player pos x: %d, y:%d\n",data.player.p_x,data.player.p_y);
	init_mlx(&data, &data.map);
	// printf("win width %d height %d\n",data.win_width, data.win_height);

	mlx_loop_hook(data.mlx, &render_img, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &close_win, &data);
	mlx_loop(data.mlx);
}
