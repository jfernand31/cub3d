#include "cub3D.h"

void	init_game(t_game *game)
{
	game->player.pos.x = 2.0;
	game->player.pos.y = 2.0;
	game->player.dir.x = 1.0;
	game->player.dir.y = 0.4;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.66;
}

static void	print_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		printf("%s\n", array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	ft_bzero(&game, sizeof(game));
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
		print_char_array(game.map);

		if (!run_game(&game))
		{
			free_game(&game);
			return (1);
		}
	}
	free_game(&game);
	return (0);
}
