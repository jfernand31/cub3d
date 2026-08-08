/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:59:50 by mda-enca          #+#    #+#             */
/*   Updated: 2026/08/08 11:59:51 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>

t_texture	check_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 1 && ray->step_y < 0)
		return (game->textures.no);
	if (ray->side == 1 && ray->step_y > 0)
		return (game->textures.so);
	if (ray->side == 0 && ray->step_x < 0)
		return (game->textures.we);
	return (game->textures.ea);
}

int	apply_shading(int color, t_ray *ray)
{
	double	shade;
	int		r;
	int		g;
	int		b;

	shade = 1.0 / (1.0 + ray->perp_wall_dist * 0.1);
	if (shade < 0.2)
		shade = 0.2;
	r = ((color >> 16) & 0xFF) * shade;
	g = ((color >> 8) & 0xFF) * shade;
	b = (color & 0xFF) * shade;
	return ((r << 16) | (g << 8) | b);
}

void	draw_vertical_line(t_game *game, int line_height, int x, t_ray *ray)
{
	double		step;
	double		tex_pos;
	t_draw		draw;
	t_texture	tex;

	tex = init_textures(game, ray, &draw);
	setup_draw(&draw, tex, line_height, &tex_pos);
	step = (double)tex.height / (double)line_height;
	while (draw.y < draw.end)
	{
		draw.tex_y = (int)tex_pos;
		if (draw.tex_y >= tex.height)
			draw.tex_y = tex.height - 1;
		tex_pos += step;
		draw.color = draw.data[draw.tex_y * tex.width + draw.tex_x];
		draw.color = apply_shading(draw.color, ray);
		my_mlx_pixel_put(&game->img, x, draw.y, draw.color);
		draw.y++;
	}
}

double	get_distance(t_ray *r, t_player *p)
{
	if (r->side == 0)
		return ((r->map_x - p->pos.x + (1 - r->step_x) / 2) / r->dir.x);
	return ((r->map_y - p->pos.y + (1 - r->step_y) / 2) / r->dir.y);
}

void	get_wall_x(t_ray *r, t_player *p)
{
	if (r->side == 0)
		r->wall_x = p->pos.y + r->perp_wall_dist * r->dir.y;
	else
		r->wall_x = p->pos.x + r->perp_wall_dist * r->dir.x;
	r->wall_x -= floor(r->wall_x);
}
