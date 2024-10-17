#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <fcntl.h>
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

typedef struct {
	int	x;
	int	y;
} Position;

typedef struct {
    char    **map;
    int     collected;
    int     found_exit;
} t_fill_info;

#define WALL '1'
#define EMPTY '0'
#define COLLECTABLE 'C'
#define EXIT 'E'
#define PLAYER 'P'
#define BUFFER_SIZE 5
#define CAT "textures/cat_sprite.xpm"
#define BBC "textures/big_bad_cat.xpm"

//map
s_map *init_map(const char *path);

//map parse utils
int	count_row(const char *path);
s_map	*alloc_map(s_map *map, int rows);
void	ft_map_row_cp(char **dest, char *src);

//map validation utils
char **copy_map(s_map *map_data);
void free_map_copy(char **map_copy, int rows);
Position find_player_start(s_map *map_data);
int flood_fill(t_fill_info *info, Position pos, int rows, int cols);
void count_components(s_map *map_data, Position *player_start, int *exits, int *players);

//map validations
int check_valid_path(s_map *map_data, Position player_start);
int is_rectangular(s_map *map_data);
int is_surrounded_by_walls(s_map *map_data);
int check_map_components(s_map *map_data, Position *player_start);
int	entity_check(s_map *map_data);
int validate_map(s_map *map_data);

// print utils
void	ft_print_map(s_map *map_data);

//event handlers
int	close_win(s_mlx *mlx_data);
int	handle_keypress(int keysym, s_mlx *mlx_data);


#endif
