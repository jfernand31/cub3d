/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:31:18 by mda-enca          #+#    #+#             */
/*   Updated: 2026/07/09 12:31:19 by mda-enca         ###   ########.fr       */
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

void	set_direction(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'N')
		set_orientation(&game->player.dir, &game->player.plane, 0, -1);
	else if (game->map[y][x] == 'S')
		set_orientation(&game->player.dir, &game->player.plane, 0, 1);
	else if (game->map[y][x] == 'W')
		set_orientation(&game->player.dir, &game->player.plane, -1, 0);
	else
		set_orientation(&game->player.dir, &game->player.plane, 1, 0);
}

void	set_orientation(t_vec2 *dir, t_vec2 *plane, double dx, double dy)
{
	dir->x = dx;
	dir->y = dy;
	plane->x = -dy * CAMERA_PLANE;
	plane->y = dx * CAMERA_PLANE;
}

int	walkable_check(char c)
{
	if (c == '0' || c == 'N' || c == 'S'
		|| c == 'E' || c == 'W')
		return (0);
	return (1);
}
