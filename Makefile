# Paths and Files
MLX_PATH = ./mlx
MLX_LIB = $(MLX_PATH)/libmlx.a
MLX_FLAGS = -L$(MLX_PATH) -Lmlx -lmlx -lXext -lX11
# CFLAGS = -Wall -Wextra -Werror
CFLAGS =
#remeber to put cflags back

# Source and object files
SRCS = src/main.c  # Add other source files as needed
OBJS = $(SRCS:.c=.o)

# Compiler
CC = gcc

# Executable name
NAME = so_long

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compile the MiniLibX library
$(MLX_LIB):
	@$(MAKE) -C $(MLX_PATH)

# Clean object files
clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(MLX_PATH) clean

# Clean object files and executable
fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(MLX_PATH) fclean

# Recompile everything
re: fclean all

# Compile .o files
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_PATH) -c $< -o $@

.PHONY: all clean fclean re
