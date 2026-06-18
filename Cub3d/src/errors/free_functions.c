#include "cub3D.h"

void	free_map(char **map, int map_h)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < map_h)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures(t_textures *textures)
{
	if (!textures)
		return ;
	free(textures->ea_path);
	free(textures->we_path);
	free(textures->so_path);
	free(textures->no_path);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx && game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	free_map(game->map, game->map_h);
	free_textures(&game->textures);
}
