#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	t_map	*map;

	data.move_counter = 0;
	map = (init_map(argv[1]));
	data.map =*(map);
	free(map);
	if (!(data.map.map))
		return 1;
	init_player(&data);
	init_mlx(&data, &data.map);
	render_img(&data);
	mlx_loop_hook(data.mlx, &render_img, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.mlx_win, DestroyNotify, StructureNotifyMask, &close_win, &data);
	mlx_loop(data.mlx);
	free_all(&data);
}
