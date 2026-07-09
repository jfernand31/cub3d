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

#include "cub3D.h"

void	free_loaded_textures(t_game *game)
{
	if (game->textures.no.img)
		mlx_destroy_image(game->mlx, game->textures.no.img);
	if (game->textures.so.img)
		mlx_destroy_image(game->mlx, game->textures.so.img);
	if (game->textures.we.img)
		mlx_destroy_image(game->mlx, game->textures.we.img);
	if (game->textures.ea.img)
		mlx_destroy_image(game->mlx, game->textures.ea.img);
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
	free_loaded_textures(game);
}
