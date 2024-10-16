# Paths and Files
MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

PRINTF_PATH = ./ft_printf
PRINTF_LIB = $(PRINTF_PATH)/libftprintf.a

# CFLAGS = -Wall -Wextra -Werror
CFLAGS =

# Source and object files
MAP_PATH = ./src/map
SRCS = src/main.c src/get_next_line/get_next_line.c src/get_next_line/get_next_line_utils.c \
		$(MAP_PATH)/initialise.c # Add other source files as needed
OBJS = $(SRCS:.c=.o)

# Compiler
CC = gcc

# Executable name
NAME = so_long

# Rules
all: $(NAME)
	 @echo "\033[32m[so_long is ready for use]\033[0m"

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(NAME)

# Compile the MiniLibX library
$(MLX_LIB):
	@$(MAKE) -C $(MLX_PATH)

# Compile the libft library
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

# Compile the ft_printf library
$(PRINTF_LIB):
	@$(MAKE) -C $(PRINTF_PATH)

# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(PRINTF_PATH) clean
	@echo "\033[33m[Cleaned up]\033[0m"

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(PRINTF_PATH) fclean
	@echo "\033[33m[Fully cleaned up]\033[0m"

# Recompile everything
re: fclean all

# Compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -I$(LIBFT_PATH) -I$(PRINTF_PATH) -c $< -o $@

.PHONY: all clean fclean re
