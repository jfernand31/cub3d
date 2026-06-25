# **************************************************************************** #
#                                    Config                                    #
# **************************************************************************** #

MAKE = make 
SHELL = bash

# **************************************************************************** #
#                                    Names                                     #
# **************************************************************************** #

NAME = cub3d

# **************************************************************************** #
#                                    Paths                                     #
# **************************************************************************** #

MLX_PATH						= ./libs/minilibx-linux/
MLX_NAME						= libmlx_Linux.a
MLX									= $(MLX_PATH)$(MLX_NAME)

LIB_PATH						=	./libs/libft/
LIB_NAME						= libft.a
LIB									= $(LIB_PATH)$(LIB_NAME)

PRINTF_PATH					= ./libs/libft/src/ft_printf/
PRINTF_NAME					= libftprintf.a
PRINTF							= $(PRINTF_PATH)$(PRINTF_NAME)

INC_PATH						= ./include/

SRC_PATH						= ./src/

SRC_FILES						= main.c

ERRORS_SRC_PATH				= $(SRC_PATH)errors/

ERRORS_SRC_FILES				= error_handling.c
ERRORS_SRC_FILES				+= free_functions.c
ERRORS_SRC_FILES				+= clean_gnl.c

EVENTS_SRC_PATH			= $(SRC_PATH)events/

EVENTS_SRC_FILES		= events.c

GAME_SRC_PATH				=$(SRC_PATH)game/

GAME_SRC_FILES			= game.c

PARSING_SRC_PATH		=$(SRC_PATH)parsing/

PARSING_SRC_FILES		= extension_checks.c
PARSING_SRC_FILES		+= parsing.c
PARSING_SRC_FILES		+= utils_parsing.c
PARSING_SRC_FILES		+= textures_parsing.c
PARSING_SRC_FILES		+= color_parsing.c
PARSING_SRC_FILES		+= map_parsing.c
PARSING_SRC_FILES		+= utils_map.c
PARSING_SRC_FILES		+= map_validation.c

PLAYER_SRC_PATH			= $(SRC_PATH)player/

PLAYER_SRC_FILES		= movement.c
PLAYER_SRC_FILES		+= player_update.c

RAYCASTING_SRC_PATH	= $(SRC_PATH)raycasting/

RAYCASTING_SRC_FILES	= raycast.c

RENDER_SRC_PATH			= $(SRC_PATH)render/

RENDER_SRC_FILES		= draw.c
RENDER_SRC_FILES		+= render.c

SRC									= $(addprefix $(SRC_PATH), $(SRC_FILES))
SRC									+= $(addprefix $(ERRORS_SRC_PATH), $(ERRORS_SRC_FILES))
SRC									+= $(addprefix $(EVENTS_SRC_PATH), $(EVENTS_SRC_FILES))
SRC									+= $(addprefix $(GAME_SRC_PATH), $(GAME_SRC_FILES))
SRC									+= $(addprefix $(RAYCASTING_SRC_PATH), $(RAYCASTING_SRC_FILES))
SRC									+= $(addprefix $(RENDER_SRC_PATH), $(RENDER_SRC_FILES))
SRC									+= $(addprefix $(PLAYER_SRC_PATH), $(PLAYER_SRC_FILES))
SRC									+= $(addprefix $(PARSING_SRC_PATH), $(PARSING_SRC_FILES))

OBJS_DIR						= Obj
OBJS								= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRC))

# **************************************************************************** #
#                                   Compiler                                   #
# **************************************************************************** #

CC              = cc
CFLAGS          = -Wall -Wextra -Werror -g
MLXFLAGS				= -L $(MLX_PATH) -lm -lmlx -Ilmlx -lXext -lX11
INC             = -I $(INC_PATH)
INC							+= -I $(LIB_PATH)
INC							+= -I $(LIB_PATH)/src/get_next_line/
INC							+= -I $(MLX_PATH)
INC							+= -I $(PRINTF_PATH)

# **************************************************************************** #
#                                   Commands                                   #
# **************************************************************************** #

RM              = rm -rf

# **************************************************************************** #
#                                    Rules                                     #
# **************************************************************************** #
 
all: $(LIB) $(MLX) $(NAME)

$(LIB): 
	@$(MAKE) -C $(PRINTF_PATH)
	@$(MAKE) -C $(LIB_PATH)

$(MLX):
	@$(MAKE) -C $(MLX_PATH)

$(OBJS_DIR):
	@mkdir -p Obj
	@echo "Objects directory created!"

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(INC) $(OBJS) $(LIB) $(PRINTF) $(MLX) $(MLXFLAGS) -o $(NAME)
	@echo "Compilation completed!"

clean:
	@$(MAKE) clean -C $(LIB_PATH)
	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(OBJS)
	@echo "Objects removed successfully!"

fclean: clean
	@$(MAKE) fclean -C $(LIB_PATH)
##	@$(MAKE) clean -C $(MLX_PATH)
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "Program removed successfully!"

re: fclean all
		@echo "Re-compile was successfull!"

.PHONY: all clean fclean re
