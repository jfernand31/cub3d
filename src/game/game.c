#include "../../include/cub3D.h"

int	game_loop(t_game *game)
{
	update_player(game);
	render(game);
	return (0);
}

bool	run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (false);
	if (!load_textures(game))
		return (false);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!game->win)
		return (false);
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	if (!game->img.img)
		return (false);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel,
			&game->img.line_length, &game->img.endian);
	if (!game->img.addr)
		return (false);
	mlx_loop_hook(game->mlx, (int (*)())game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, (int (*)())handle_key_press, game);
	mlx_hook(game->win, 3, 1L << 1, (int (*)())handle_key_release, game);
	mlx_hook(game->win, 17, 0, (int (*)())close_game, game);
	mlx_loop(game->mlx);
	return (true);
}
