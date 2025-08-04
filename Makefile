NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -I include -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_FLAGS = -lmlx -lXext -lX11 -lm -lz

SRCS = src/main/main.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft

$(LIBFT):
	@echo "Building libft..."
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "Cleaning objects..."
	@rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Removing executable..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
