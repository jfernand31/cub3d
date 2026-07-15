/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:31:38 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 22:41:55 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"
#include <math.h>

t_texture	check_wall(t_game *game, t_ray *ray)
{
	if (ray->side == 1 && ray->step_y > 0)
		return (game->textures.no);
	if (ray->side == 1 && ray->step_y < 0)
		return (game->textures.so);
	if (ray->side == 0 && ray->step_x > 0)
		return (game->textures.we);
	if (ray->side == 0 && ray->step_x < 0)
		return (game->textures.ea);
	return (game->textures.no);
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

int	set_tex_x(t_ray *ray, t_texture *tex)
{
	int	tex_x;

	tex_x = (int)(ray->wall_x * tex->width);
	if (tex_x >= tex->width)
		tex_x = tex->width - 1;
	if (ray->side == 0 && ray->dir.x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->dir.y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

double	get_distance(t_ray *r, t_player *p)
{
	if (r->side == 0)
		return ((r->map_x - p->pos.x + (1 - r->step_x) / 2) / r->dir.x);
	else
		return ((r->map_y - p->pos.y + (1 - r->step_y) / 2) / r->dir.y);
}

void	get_wall_x(t_ray *r, t_player *p)
{
	if (r->side == 0)
		r->wall_x = p->pos.y + r->perp_wall_dist * r->dir.y;
	else
		r->wall_x = p->pos.x + r->perp_wall_dist * r->dir.x;
	r->wall_x -= floor(r->wall_x);
	if (r->wall_x < 0)
		r->wall_x = 0;
	if (r->wall_x > 1)
		r->wall_x = 1;
}
