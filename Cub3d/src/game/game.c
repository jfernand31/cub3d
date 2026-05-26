#include "libft.h"
#include "cub3D.h"
#include "mlx.h"
#include <stdbool.h>


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
