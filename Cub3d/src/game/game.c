#include "libft.h"
#include "cub3D.h"
#include "mlx.h"
#include <stdbool.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

void	draw_minimap(t_data *img, char **map, int map_h, int map_w)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_h)
	{
		j = 0;
		while (j < map_w)
		{
			if (map[i][j] == '1')
				draw_square(img, j, i, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	load_map(t_data *img, char **map, t_game *game)
{
	draw_floor_ceiling(img, game->floor_color, game->ceiling_color);
	draw_minimap(img, map, game->map_h, game->map_w);
}

bool	run_game(t_game *game)
{
	t_data	img;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	load_map(&img, game->map, game);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_loop(game->mlx);
	return (true);
}
