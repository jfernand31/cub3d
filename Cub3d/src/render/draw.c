#include "cub3D.h"

void	draw_square_pixel(t_data *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while(j < 4)
	{
		i = 0;
		while (i < 4)
		{
			my_mlx_pixel_put(img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}


void	draw_square(t_data *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < MINIMAP_SCALE)
	{
		i = 0;
		while (i < MINIMAP_SCALE)
		{
			my_mlx_pixel_put(img,
				x * MINIMAP_SCALE + i,
				y * MINIMAP_SCALE + j,
				color);
			i++;
		}
		j++;
	}
}

void	draw_floor_ceiling(t_data *img, int floor, int ceiling)
{
	int i;
	int j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT / 2)
				my_mlx_pixel_put(img, j, i, ceiling);
			else
				my_mlx_pixel_put(img, j, i, floor);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *img, char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (map[i][j] == '1')
				draw_square(img, j, i, 0x00FFF000);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *img, t_player *player)
{
	int	x;
	int	y;

	x = player->pos.x * MINIMAP_SCALE;
	y = player->pos.y * MINIMAP_SCALE;

	draw_square_pixel(img, x, y, 0xFFFFFF);
}
