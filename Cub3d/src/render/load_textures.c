/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:42:45 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 22:53:14 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (true);
}
