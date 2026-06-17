#include "cub3D.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->player.pos.x = 2.0;
	game->player.pos.y = 2.0;
	game->player.dir.x = 1.0;
	game->player.dir.y = 0.4;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.66;
	game->map_w = 0;
	game->map_h = 0;
	game->ceiling_color = 0;
	game->floor_color = 0;
	game->ceiling_set = 0;
	game->floor_set = 0;
	game->keys.w = false;
	game->keys.a = false;
	game->keys.s = false;
	game->keys.d = false;
	game->keys.left = false;
	game->keys.right = false;
	game->textures.ea_path = NULL;
	game->textures.we_path = NULL;
	game->textures.no_path = NULL;
	game->textures.so_path = NULL;
}


void	free_game(t_game *game)
{
	
	if (game->map)
	{
		int i = 0;
		while (i < game->map_h)
		{
			free(game->map[i]);
			i++;
		}
	}
}

static void print_map(t_game *game)
{
	int i = 0;

	printf("Map size: %d x %d\n", game->map_w, game->map_h);
	printf("Floor color: %d\n", game->floor_color);
	printf("Ceiling color: %d\n", game->ceiling_color);

	while (game->map[i])
	{
		printf("%s\n", game->map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if(argc != 2)
	{
		ft_printf("Usage is: ./cub3D <map.cub>\n");
		return (1);
	}
	if (check_extension(argv[1]) == 0)
	{
		init_game(&game);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (1); //error opening map
		if (parsing(argv[1], &game) == -1)
			return (1); //error in the parsing.


		//rude_parse_map(argv[1], &game);
		if (!game.map)
			return (1);
//		if (!run_game(&game))
//		{
//			free_game(&game);
//			return (1);
//		}
		print_map(&game);
	}
	free_game(&game);
	return (0);
}
