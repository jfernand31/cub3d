/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:45:05 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 22:53:26 by jfernand         ###   ########.fr       */
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
