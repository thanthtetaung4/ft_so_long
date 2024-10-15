#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdio.h>
#include <mlx.h>
#include "./libft/libft.h"
#include "./src/get_next_line/get_next_line.h"

typedef struct t_map
{
	char	**map;
	int		rows;
	int		cols;
}s_map;


#define BUFFER_SIZE 5
#define CAT "textures/cat_sprite.xpm"
#define BBC "textures/big_bad_cat.xpm"

//map
s_map *init_map(const char *path);

#endif
