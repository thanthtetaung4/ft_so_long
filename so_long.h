/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taung <taung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 17:21:35 by taung             #+#    #+#             */
/*   Updated: 2024/10/20 17:25:26 by taung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "./libft/libft.h"
# include "./src/get_next_line/get_next_line.h"

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
	int		collectables;
}	t_map;

typedef struct s_player
{
	int	p_x;
	int	p_y;
	int	win;
	int	points;
}	t_player;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
}	t_img;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_win;
	int			win_height;
	int			win_width;
	int			move_counter;
	t_player	player;
	t_img		images[5];
	t_map		map;
}	t_data;

typedef struct s_pos{
	int	x;
	int	y;
}	t_Position;

typedef struct s_fill_info{
	char	**map;
	int		collected;
	int		found_exit;
}	t_fill_info;

# define WALL '1'
# define EMPTY '0'
# define COLLECTABLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define CAT_IMG "textures/cat.xpm"
# define WALL_IMG "textures/wall.xpm"
# define PATH_IMG "textures/path.xpm"
# define FISH_IMG "textures/fish.xpm"
# define EXIT_IMG "textures/bed.xpm"
# define IMAGE_SIZE 40

//map
t_map		*init_map(const char *path);

//map utilities
void		update_map(t_data *data, int x, int y, char entity);

//map parse utils
int			count_row(const char *path);
t_map		*alloc_map(t_map *map, int rows);
void		ft_map_row_cp(char **dest, char *src);
int			path_check(const char *path);

//map validation utils
char		**copy_map(t_map *map_data);
void		free_map_copy(char **map_copy, int rows);
t_Position	find_player_start(t_map *map_data);
int			flood_fill(t_fill_info *info, t_Position pos, int rows, int cols);
void		count_components(t_map *map_data, t_Position *player_start,
				int *exits, int *players);

//map validations
int			check_valid_path(t_map *map_data, t_Position player_start);
int			is_rectangular(t_map *map_data);
int			is_surrounded_by_walls(t_map *map_data);
int			check_map_components(t_map *map_data, t_Position *player_start);
int			entity_check(t_map *map_data);
int			validate_map(t_map *map_data);

// print utils
void		ft_print_map(t_map *map_data);

//event handlers
int			close_win(t_data *data);
int			handle_keypress(int keysym, t_data *data);

// rendering
int			render_img(t_data *data);
void		init_img(t_data *data);

//rendering utils
void		init_mlx(t_data *data, t_map *map);
void		calc_win_dimensions(t_map *map, t_data *data);
void		parse_chars(t_data *data, int i, int j);
void		render_player(t_data *data);

//player
void		init_player(t_data *data);
void		move_player(t_data *data, int x, int y);
void		get_pos_from_map(t_data *data);

//player utils
int			is_valid_move(t_data *data, int x, int y);
int			is_exit(t_data *data, int x, int y);
int			is_collectable(t_data *data, int x, int y);

//game
void		win(t_data *data);

//free
void		free_all(t_data	*data);

#endif
