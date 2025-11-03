NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror

MLX_DIR = ./lib/minilibx-linux
# MLX_DIR = ./lib/minilibx-macos
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -g3
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_SRC = mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
	mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
	mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
	mlx_int_wait_first_expose.c mlx_int_get_visual.c mlx_flush_event.c \
	mlx_string_put.c mlx_set_font.c mlx_new_image.c mlx_get_data_addr.c \
	mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
	mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
	mlx_rgb.c mlx_destroy_image.c mlx_mouse.c mlx_screen_size.c \
	mlx_destroy_display.c
MLX_SRC := $(addprefix $(MLX_DIR)/,$(MLX_SRC))
SRCS = src/main.c \
		\
		src/parsing/check_file.c \
		\
		src/parsing/scene_set/ambiant_set.c \
		src/parsing/scene_set/camera_set.c \
		src/parsing/scene_set/color_set.c \
		src/parsing/scene_set/light_set.c \
		src/parsing/scene_set/sphere_set.c \
		src/parsing/scene_set/cylinder_set.c \
		src/parsing/scene_set/plane_set.c \
		\
		\
		src/parsing/utils/get_set_data.c \
		src/parsing/utils/valid_range.c \
		src/parsing/utils/parse_coordinates.c \
		src/parsing/utils/validate_line_chars.c \
		\
		src/display/create_ray_from_pixel.c \
		src/display/put_pixel.c \
		src/display/loop.c \
		src/display/draw.c \
		\
		src/display/plane/hit_plane.c \
		\
		src/display/cylinder/hit_cylinder.c \
		src/display/cylinder/hit_circle.c \
		src/display/cylinder/get_cylinder_normal.c \
		\
		src/display/sphere/hit_sphere.c \
		src/display/sphere/get_sphere_normal.c \
		\
		src/display/light/utils.c \
		src/display/light/add_light.c \
		src/display/light/get_normal.c \
		\
		src/utils/ft_strlen.c \
		src/utils/ft_is_digit.c \
		src/utils/exit_error.c \
		src/utils/skip_whitespace.c \
		src/utils/safe_open.c \
		src/utils/safe_atoi.c \
		src/utils/ft_atoi.c \
		src/utils/return_color.c \
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
		src/math/distance.c \
		src/math/get_hit_point.c \
		src/math/deg2rad.c \
		src/math/v_add.c \
		src/math/v_cross.c \
		src/math/v_dot.c \
		src/math/v_len.c \
		src/math/v_norm.c \
		src/math/v_scale.c \
		src/math/v_sub.c \
		src/math/set_vec.c

HEADER = include/mini_rt.h	\
		 include/struct.h

all: $(NAME)

$(NAME): $(SRCS) $(HEADER) $(MLX_LIB)
	$(CC) $(CFLAGS) -Iinclude -o $(NAME) $(SRCS) $(MLX_FLAGS)

$(MLX_LIB): $(MLX_SRC)
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
