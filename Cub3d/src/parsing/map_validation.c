/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:58:33 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 19:58:59 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	validate_map(t_game *game)
{
	int	x;
	int	y;
	int	player;

	y = 0;
	player = 0;
	while (y < game->map_h)
	{
		x = 0;
		while (x < game->map_w)
		{
			if (!ft_strchr("X01NSWE", game->map[y][x]))
				return (-1);
			if (ft_strchr("NSWE", game->map[y][x]))
			{
				player++;
				if (player == 1)
					set_start(game, y, x);
			}
			if (walkable_check(game->map[y][x]) == 0 &&
				surrounding_check(game, y, x) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	if (player != 1)
		return (-1);
	return (0);
}

void	set_start(t_game *game, int y, int x)
{
	game->player.pos.x = x + 0.5;
	game->player.pos.y = y + 0.5;
	set_direction(game, y, x);
	game->map[y][x] = '0';
}

/* -1  (one row above / one column left)
	0  (same row      / same column) 
	1  (one row below / one column right)
*/

int	surrounding_check(t_game *game, int y, int x)
{
	if (adjacent_check(game, y - 1, x) == -1)
		return (-1);
	if (adjacent_check(game, y + 1, x) == -1)
		return (-1);
	if (adjacent_check(game, y, x - 1) == -1)
		return (-1);
	if (adjacent_check(game, y, x + 1) == -1)
		return (-1);
	return (0);
}

int	adjacent_check(t_game *game, int y, int x)
{
	if (y < 0 || y >= game->map_h || x < 0 || x >= game->map_w)
		return (-1);
	if (game->map[y][x] == 'X')
		return (-1);
	return (0);
}
