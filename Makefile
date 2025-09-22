NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./lib/minilibx-linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_LIB = $(MLX_DIR)/libmlx.a

SRCS = src/main.c \
		src/parsing/parsing.c \
		src/parsing/parsing2.c \
		src/parsing/parsing_utils.c \
		\
		src/display/loop.c \
		src/display/draw.c \
		src/display/draw3d.c \
		\
		src/utils/ft_strlen.c \
		src/utils/ft_is_digit.c \
		src/utils/exit_error.c \
		src/utils/open_check.c \
		\
		src/utils/convert/ft_atoi.c \
		src/utils/convert/safe_atonbr.c \
		\
		src/utils/get_line/get_next_line.c \
		src/utils/get_line/get_next_line_utils.c \
		\
		src/utils/memory/ft_calloc.c \
		\
		src/utils/tools_mlx/init_app.c \
		src/utils/tools_mlx/destroy_hook.c \
		src/utils/tools_mlx/key_hook.c \
		src/utils/tools_mlx/mouse_hook.c \
		\
		src/math/deg2rad.c \
		src/math/v_add.c \
		src/math/v_cross.c \
		src/math/v_dot.c \
		src/math/v_len.c \
		src/math/v_norm.c \
		src/math/v_scale.c \
		src/math/v_sub.c \
		src/math/vec3.c

HEADER = include/mini_rt.h	\
		 include/struct.h

all: $(NAME)

$(NAME): $(SRCS) $(HEADER) $(MLX_LIB)
	$(CC) $(CFLAGS) -Iinclude -o $(NAME) $(SRCS) $(MLX_FLAGS)

$(MLX_LIB): 
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

