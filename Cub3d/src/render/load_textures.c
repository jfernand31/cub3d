#include "../../include/cub3D.h"
#include <stdbool.h>


bool	load_single_texture(void *mlx, char *path, t_texture *tex)
{
	printf("path = '%s'\n", path);
	printf("mlx = %p\n", mlx);
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	printf("img = %p\n", tex->img);
	if (!tex->img)
		return (false);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bpp, &tex->line_length, 
			       &tex->endian);
	if (!tex->addr)
		return (false);
	return (true);
}

bool	load_textures(t_game *game)
{
	if (!load_single_texture(game->mlx, game->textures.no_path, 
			  &game->textures.no))
	{
		free_loaded_textures(game);
		return (false);
	}
	if (!load_single_texture(game->mlx, game->textures.so_path, 
			  &game->textures.so))
	{
		free_loaded_textures(game);
		return (false);
	}
	if (!load_single_texture(game->mlx, game->textures.we_path, 
			  &game->textures.we))
	{
		free_loaded_textures(game);
		return (false);
	}
	if (!load_single_texture(game->mlx, game->textures.ea_path, 
			  &game->textures.ea))
	{
		free_loaded_textures(game);
		return (false);
	}
	printf("Depois do load:\n");
	printf("NO %d %d\n", game->textures.no.width, game->textures.no.height);
	printf("SO %d %d\n", game->textures.so.width, game->textures.so.height);
	printf("WE %d %d\n", game->textures.we.width, game->textures.we.height);
	printf("EA %d %d\n", game->textures.ea.width, game->textures.ea.height);
	return (true);
}

