# Paths and Files
MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

CFLAGS = -Wall -Wextra -Werror
# CFLAGS =

# Source and object files
MAP_PATH = ./src/map
WIN_CTRL_PATH = ./src/win_ctrl
UTILS_PATH = ./src/utils
RENDER_PATH = ./src/render
GAME_PATH = ./src/game
FREE_PATH = ./src/free
SRCS = src/main.c src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c \
		$(UTILS_PATH)/print_utils.c $(MAP_PATH)/initialise.c $(MAP_PATH)/parse_utils.c \
		$(MAP_PATH)/map_validations.c $(MAP_PATH)/validation_utils.c $(WIN_CTRL_PATH)/win_ctrl.c \
		$(RENDER_PATH)/img_utils.c $(RENDER_PATH)/render_utils.c $(RENDER_PATH)/render.c \
		$(GAME_PATH)/player.c $(GAME_PATH)/game.c $(MAP_PATH)/map_utils.c $(GAME_PATH)/player_utils.c\
		$(FREE_PATH)/free_utils.c# Add other source files as needed
OBJS = $(SRCS:.c=.o)

# Compiler
CC = gcc

# Executable name
NAME = so_long

# Rules
all: $(NAME)
	 @echo "\033[32m[so_long is ready for use]\033[0m"

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) -lft -o $(NAME)

# Compile the MiniLibX library
$(MLX_LIB):
	@$(MAKE) -C $(MLX_PATH)

# Compile the libft library
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# Test
TEST = mytest
TEST_PATH = ./test
TEST_SRCS = $(TEST_PATH)/render_test.c
TETST_OBJS = $(TEST_SRCS:.c=.o)
test: $(TEST)
	 @echo "\033[32m[$(test) is ready for use]\033[0m"

$(TEST): $(TETST_OBJS) $(MLX_LIB) $(LIBFT)
	$(CC) $(CFLAGS) $(TETST_OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) -lft -o $(TEST)
# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
# @$(MAKE) -C $(PRINTF_PATH) clean
	@echo "\033[33m[Cleaned up]\033[0m"

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "\033[33m[Fully cleaned up]\033[0m"

# Recompile everything
re: fclean all

# Compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -c $< -o $@

.PHONY: all clean fclean re
