#include "../so_long.h"

int	main(void)
{
	void	*mlx_img;
	int		img_width;
	int		img_height;
	s_mlx	mlx_data;

	int		p_x = 0,p_y = 0;

	// mlx_data = malloc(sizeof(s_mlx));
	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, 500, 500, "so_long");
	// printf("img_width: %i, img_height: %i\n",img_width, img_height);
	// mlx_img = mlx_xpm_file_to_image(mlx_data.mlx, BBC, &img_width, &img_height);

	// if(!mlx_img)
	// 	printf("BAD IMAGE\n");
	// else
	// 	printf("IMG OK\n");
	// printf("img_width: %i, img_height: %i\n",img_width, img_height);
	// while(p_x < 500) //Change this to wasd movement
	// {
	// 	mlx_clear_window(mlx_data.mlx,mlx_data.win);
	// 	mlx_put_image_to_window(mlx_data.mlx, mlx_data.win, mlx_img, p_x, p_y);
	// 	p_x += 50;
	// 	p_y += 10;
	// 	ft_printf("moving\n");
	// 	usleep(40000);
	// }
	mlx_hook(mlx_data.win, KeyPress, KeyPressMask, &handle_keypress, &mlx_data);
	mlx_hook(mlx_data.win, DestroyNotify, StructureNotifyMask, &close_win, &mlx_data);
	mlx_loop(mlx_data.mlx);
}
// #include "../so_long.h"

// int	main(int argc, char **argv)
// {
// 	int			fd;
// 	const char	*path;
// 	s_map		*map;
// 	char		*res;

// 	map = init_map(argv[1]);
// 	// printf("%ld\n",ft_strlen(path));
// }
