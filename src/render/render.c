#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


int	render(void *param)
{
	t_game	*game;

	game = (t_game *)param;

	draw_floor_ceiling(&game->img,
		game->floor_color,
		game->ceiling_color);
	raycast(game, game->map, &game->player, &game->img);
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
