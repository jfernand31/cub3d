/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:32:17 by mda-enca          #+#    #+#             */
/*   Updated: 2026/07/09 12:32:18 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	destroy_texture(void *mlx, t_texture *texture)
{
	if (mlx && texture->img)
		mlx_destroy_image(mlx, texture->img);
	texture->img = NULL;
	texture->addr = NULL;
}

void	free_loaded_textures(t_game *game)
{
	if (!game)
		return ;
	destroy_texture(game->mlx, &game->textures.no);
	destroy_texture(game->mlx, &game->textures.so);
	destroy_texture(game->mlx, &game->textures.we);
	destroy_texture(game->mlx, &game->textures.ea);
	free_textures(&game->textures);
}

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
	textures->ea_path = NULL;
	textures->we_path = NULL;
	textures->so_path = NULL;
	textures->no_path = NULL;
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx && game->img.img)
		mlx_destroy_image(game->mlx, game->img.img);
	game->img.img = NULL;
	game->img.addr = NULL;
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	game->win = NULL;
	free_map(game->map, game->map_h);
	game->map = NULL;
	free_loaded_textures(game);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}
