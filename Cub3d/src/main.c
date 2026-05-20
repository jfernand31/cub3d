#include "cub3D.h"
#include "libft.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	ft_memset(&game->player, 0, sizeof(t_player));
}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_game	game;

	init_game(&game);

	return (0);
}
