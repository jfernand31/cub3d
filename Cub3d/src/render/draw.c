/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:42:25 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 22:51:31 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	texture_pixel(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (x < 0 || x >= tex->width)
		return (0);
	if (y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_length) + (x * (tex->bpp / 8));
	return (*(unsigned int *)pixel);
}

void	draw_player(t_data *img, t_player *player)
{
	int	x;
	int	y;

	x = player->pos.x * MINIMAP_SCALE;
	y = player->pos.y * MINIMAP_SCALE;
	draw_square_pixel(img, x, y, 0xFFFFFF);
}
