/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:59:56 by mda-enca          #+#    #+#             */
/*   Updated: 2026/08/08 11:59:57 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	((unsigned int *)img->addr)
	[y * (img->line_length / 4) + x] = color;
}

void	draw_square_pixel(t_data *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			put_pixel(img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_square(t_data *img, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < MINIMAP_SCALE)
	{
		i = 0;
		while (i < MINIMAP_SCALE)
		{
			put_pixel(img,
				x * MINIMAP_SCALE + i,
				y * MINIMAP_SCALE + j,
				color);
			i++;
		}
		j++;
	}
}

void	draw_floor_ceiling(t_data *img, int floor, int ceiling)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			put_pixel(img, x++, y, ceiling);
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			put_pixel(img, x++, y, floor);
		y++;
	}
}

void	draw_minimap(t_data *img, char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			if (map[i][j] == '1')
				draw_square(img, j, i, 0x00FFF000);
			j++;
		}
		i++;
	}
}
