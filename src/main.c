#include "../so_long.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_img;
	//char	*img_path = "./wall.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "so_long");
	printf("img_width: %i, img_height: %i\n",img_width, img_height);
	mlx_img = mlx_xpm_file_to_image(mlx, BBC, &img_width, &img_height);

	if(!mlx_img)
		printf("BAD IMAGE\n");
	else
		printf("IMG OK\n");
	printf("img_width: %i, img_height: %i\n",img_width, img_height);
	mlx_put_image_to_window(mlx, mlx_win, mlx_img, img_width, img_height);
	mlx_loop(mlx);
}
