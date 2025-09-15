NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./lib/minilibx_macos
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
MLX_LIB = $(MLX_DIR)/libmlx.a

SRCS = src/main.c src/ft_atoi.c src/get_next_line_utils.c src/get_next_line.c src/parsing.c src/parsing2.c \
 		src/parsing_utils.c src/utils.c src/ft_calloc.c \
		src/destroy_hook.c src/init_app.c src/key_hook.c src/vec3.c

HEADER = include/mini_rt.h	\
		 include/struct.h

all: $(NAME)

$(NAME): $(SRCS) $(MLX_LIB) $(HEADER)
	$(CC) $(CFLAGS) -Iinclude -I$(MLX_DIR) -o $(NAME) $(SRCS) $(MLX_FLAGS)

$(MLX_LIB):
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
