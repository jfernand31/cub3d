#include "cub3D.h"

int	validate_map(t_game *game)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (!ft_strchr("X01NSWE", game->map[y][x]))
				return (-1); //error needs handling.
			if (ft_strchr("NSWE", game->map[y][x]))
			{
				player++;
				if (player == 1)
					set_start(game, y, x);
			}
			if (walkable_check(game->map[y][x]) == 0 &&
				surrounding_check(game, y, x) == -1)
				return (-1); //error needs handling.
			x++;
		}
		y++;
	}
	if (player != 1)
		return (-1); //error needs handling.
	return (0);
}

void	set_start(t_game *game, int y, int x)
{
	game->player.pos.x = x * TILE_SIZE + TILE_SIZE / 2.0;
	game->player.pos.y = y * TILE_SIZE + TILE_SIZE / 2.0;
	set_direction(game, y, x);
	//game->map[y][x] = '0'; (not sure)
}

/* -1  (one row above / one column left)
	0  (same row      / same column) 
	1  (one row below / one column right)
*/

int	surrounding_check(t_game *game, int y, int x)
{
	int	row_step;
	int	col_step;
	int	adj_row;
	int	adj_col;

	row_step = -1;
	while (row_step <= 1)
	{
		col_step = -1;
		while (col_step <= 1)
		{
			if (row_step != 0 || col_step != 0)
			{
				adj_row = y + row_step;
				adj_col = x + col_step;
				if (adj_row < 0 || adj_row >= game->map_h ||
					adj_col < 0 || adj_col >= game->map_w)
					return (-1);
				if (game->map[adj_row][adj_col] == 'X')
					return (-1);
			}
			col_step++;
		}
		row_step++;
	}
	return (0);
}
