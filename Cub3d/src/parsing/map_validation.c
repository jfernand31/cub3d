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

			}
			x++;
		}
		y++;
	}
}
