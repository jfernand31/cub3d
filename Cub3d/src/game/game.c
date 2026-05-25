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
				draw_square(img, j, i, 0x00FF0000);
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

int	render(void *param)
{
	t_game	*game;

	game = (t_game *)param;

	draw_floor_ceiling(&game->img,
		game->floor_color,
		game->ceiling_color);
	draw_minimap(&game->img, game->map, game);
	draw_player(&game->img, &game->player);

	mlx_put_image_to_window(
		game->mlx,
		game->win,
		game->img.img,
		0,
		0
	);

	return (0);
}

bool	run_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
	mlx_loop_hook(game->mlx, (int (*)())render, game);
	mlx_hook(game->win, 2, 1L << 0, (int (*)())handle_key_press, game);
	mlx_hook(game->win, 17, 0, (int (*)())close_game, game);
	mlx_loop(game->mlx);
	return (true);
}
