#include "cub3D.h"
#include <stdlib.h>

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_game(game);
		exit(0);
	}
	return (0);
}
