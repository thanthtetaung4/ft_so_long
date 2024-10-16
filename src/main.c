#include "../so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	int		img_width;
	int		img_height;

	int		p_x = 0,p_y = 0;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "so_long");
	printf("img_width: %i, img_height: %i\n",img_width, img_height);
	mlx_img = mlx_xpm_file_to_image(mlx, BBC, &img_width, &img_height);

	if(!mlx_img)
		printf("BAD IMAGE\n");
	else
		printf("IMG OK\n");
	printf("img_width: %i, img_height: %i\n",img_width, img_height);
	while(p_x < 500)
	{
		mlx_clear_window(mlx,mlx_win);
		mlx_put_image_to_window(mlx, mlx_win, mlx_img, p_x, p_y);
		p_x += 50;
		p_y+= 10;
		ft_printf("moving\n");
		usleep(50000);
	}
	mlx_loop(mlx);
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
