#include "libft.h"
#include "cub3D.h"
#include "mlx.h"
#include <stdbool.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

bool	run_game(t_game *game)
{
	t_data	img;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, 1920, 1080, "Cub3D");
	img.img = mlx_new_image(game->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_loop(game->mlx);
	return (true);
}
