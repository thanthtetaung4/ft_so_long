#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <mlx.h>
#include <X11/keysym.h>
#include <X11/X.h>
#include "./libft/libft.h"
#include "./src/get_next_line/get_next_line.h"
// #include "./ft_printf/ft_printf.h"

typedef struct t_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collectables;
}s_map;

typedef struct t_player
{
	int	p_x;
	int	p_y;
	int	win;
} s_player;

typedef struct t_mlx
{
	void	*mlx;
	void	*win;
} s_mlx;

#define BUFFER_SIZE 5
#define CAT "textures/cat_sprite.xpm"
#define BBC "textures/big_bad_cat.xpm"

//map
s_map *init_map(const char *path);

//event handlers
int	close_win(s_mlx *mlx_data);
int	handle_keypress(int keysym, s_mlx *mlx_data);


#endif
