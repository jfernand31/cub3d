
#include "cub3D.h"

int	max_width(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	normalize_map(char *dest, char *src, int w)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < w)
	{
		dest[i] = 'X';
		i++;
	}
	dest[i] = '\0';
}

void	set_direction(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'N')
	{
		game->player.dir.x = 0;
		game->player.dir.y = -1;
		game->player.plane.x = 0.66;
		game->player.plane.y = 0;
	}
	else if (game->map[y][x] == 'S')
	{
		game->player.dir.x = 0;
		game->player.dir.y = 1;
		game->player.plane.x = -0.66;
		game->player.plane.y = 0;
	}
	else if (game->map[y][x] == 'W')
	{
		game->player.dir.x = -1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = -0.66;
	}
	else
	{
		game->player.dir.x = 1;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = 0.66;
	}
}

int	walkable_check(char c)
{
	if (c == '0' || c == 'N' || c == 'S' ||
		c == 'E' || c == 'W')
		return (0);
	return (1);
}
