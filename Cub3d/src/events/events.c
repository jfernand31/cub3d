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
	if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_D || keycode == KEY_A)
		player_movement(game, keycode);
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		player_rotate(&game->player, keycode);
	return (0);
}
