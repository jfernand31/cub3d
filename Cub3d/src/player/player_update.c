#include "cub3D.h"

void	update_player(t_game *game)
{
	player_movement(game, game->keys);
	player_rotate(&game->player, game->keys);
}
