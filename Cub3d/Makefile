NAME		= cub3d

CC		= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I./include -I./libft/include -I./minilibx-linux

# Libraries
LIBFT		= libft/libft.a
MLX		= minilibx-linux/libmlx.a
LIBS		= -L./libft -lft -L./minilibx-linux -lmlx -lX11 -lXext -lm

# Sources — add new .o files here as you create .c files
OBJ =		src/main.o \
		src/game/game.o \

# --- Rules ---

all: $(LIBFT) $(MLX) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(MLX):
	cd minilibx-linux && ./configure && sed -i 's/CFLAGS\t= -O3/CFLAGS\t= -O3 -std=gnu89/' Makefile.gen && $(MAKE) -f Makefile.gen

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
