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
	game->mlx = NULL;
	game->win = NULL;
	game->img.img = NULL;
	game->img.addr = NULL;
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if(argc != 2)
	{
		error_message(ARGS);
		return (1);
	}
	init_game(&game);
	if (check_extension(argv[1]) == -1)
		return (error_exit(&game, ARGS), 1);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (error_exit(&game, FILE), 1);
		close(fd);
		if (parsing(argv[1], &game) == -1)
			return (error_exit(&game, MAP), 1);
		if (!game.map)
			return (error_exit(&game, MAP), 1);
//		if (!run_game(&game))
//		{
//			free_game(&game);
//			return (1);
//		}
	}
	free_game(&game);
	return (0);
}
