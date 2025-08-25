NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -I include -g

LIBFT_DIR = ./libft
LIBFT_A = $(LIBFT_DIR)/libft.a

MLX_DIR = ./mlx
MLX_A = $(MLX_DIR)/libmlx.a

LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx

MLX_SYSTEM_LIBS = -lXext -lX11 -lm -lz

SRCS = srcs/main.c \
	srcs/init/data_init.c \
	srcs/init/delete.c \
	srcs/init/init_mlx.c \
	srcs/parsing/fill_t_map.c \
	srcs/parsing/get_file_data.c \
	srcs/parsing/get_swords.c \
	srcs/parsing/map_check.c \
	srcs/parsing/set_rgb_and_heights.c \
	srcs/parsing/parse_file.c \
	srcs/validate/validate_elements.c \
	srcs/validate/validate_map.c \
	srcs/validate/validate_map_grid.c \
	srcs/engine/player/player_init.c \
	srcs/engine/player/player_movement.c \
	srcs/engine/player/player_rotation.c \
	srcs/engine/raycast/perform_dda.c \
	srcs/engine/raycast/ray_init.c \
	srcs/engine/raycast/raycaster.c \
	srcs/engine/raycast/raycaster_utils.c \
	srcs/engine/events.c \
	srcs/engine/background.c \
	srcs/utils/free_all.c \
	srcs/utils/get_color.c \
	srcs/utils/print_error.c \
	srcs/utils/cleanup.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A) $(MLX_A)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) $(MLX_SYSTEM_LIBS)

$(LIBFT_A):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	@echo "Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning project objects..."
	@rm -f $(OBJS)
	@echo "Cleaning libft..."
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Cleaning MiniLibX..."
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)
	@echo "Fcleaning libft..."
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
