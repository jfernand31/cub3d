/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:46:23 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 19:57:32 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	max_width(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	normalize_map(char *dest, char *src, int w)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < w)
	{
		dest[i] = 'X';
		i++;
	}
	dest[i] = '\0';
}

void	set_values(t_game *game, int axis, int dir, double plane)
{
	if (axis == 0)
	{
		game->player.dir.x = 0;
		game->player.dir.y = dir;
		game->player.plane.x = plane;
		game->player.plane.y = 0;
	}
	if (axis == 1)
	{
		game->player.dir.x = dir;
		game->player.dir.y = 0;
		game->player.plane.x = 0;
		game->player.plane.y = plane;
	}
}

void	set_direction(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'N')
	{
		set_values(game, 0, -1, 0.66);
	}
	else if (game->map[y][x] == 'S')
	{
		set_values(game, 0, 1, -0.66);
	}
	else if (game->map[y][x] == 'W')
	{
		set_values(game, 1, -1, -0.66);
	}
	else
	{
		set_values(game, 1, 1, 0.66);
	}
}

int	walkable_check(char c)
{
	if (c == '0' || c == 'N' || c == 'S' ||
		c == 'E' || c == 'W')
		return (0);
	return (1);
}
