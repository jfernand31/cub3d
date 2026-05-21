#include "cub3D.h"
#include "libft.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->player.pos.x = 0.0;
	game->player.pos.y = 0.0;
	game->player.dir.x = 0.0;
	game->player.dir.y = 0.0;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.66;
	game->map_w = 0;
	game->map_h = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	if(argc != 2)
	{
		ft_printf("Usage is: ./cub3D <map.cub>\n");
		return (1);
	}

	init_game(&game);
//	game->map = parse_map(argv[1], &game);
//	if (!game->map)
//		return (1);
	if (!run_game(&game))
	{
		//free_game(game);
		return (1);
	}
//	free_game(game);
	return (0);
}
