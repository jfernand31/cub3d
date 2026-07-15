/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 22:18:28 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 22:41:33 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <float.h>
#include <math.h>

void	ray_step(t_ray *ray, t_player *player)
{
	ray_step_x(ray, player);
	ray_step_y(ray, player);
}

void	ray_dda(t_game *g, t_ray *ray, char **map, t_data *img)
{
	ray->hit = 0;
	while (!ray->hit)
	{
		if (ray->map_x < 0 || ray->map_x >= g->map_w || ray->map_y < 0
			|| ray->map_y >= g->map_h)
			break ;
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->map_x += ray->step_x;
			ray->side_dist.x += ray->delta_dist.x;
			ray->side = 0;
		}
		else
		{
			ray->map_y += ray->step_y;
			ray->side_dist.y += ray->delta_dist.y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	draw_square_pixel(img, ray->map_x * MINIMAP_SCALE, ray->map_y
		* MINIMAP_SCALE, 0xFF0000);
}

void	ray_calculate_delta(t_ray *ray)
{
	if (fabs(ray->dir.x) < 1e-9)
		ray->delta_dist.x = INFINITY;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (fabs(ray->dir.y) < 1e-9)
		ray->delta_dist.y = INFINITY;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

void	draw_vertical_line(t_game *game, int line_height, int x, t_ray *ray)
{
	int			tex_x;
	int			tex_y;
	t_draw		draw;
	t_texture	tex;

	tex = check_wall(game, ray);
	tex_x = set_tex_x(ray, &tex);
	draw.data = (int *)tex.addr;
	draw.end = line_height / 2 + HEIGHT / 2;
	draw.start = -line_height / 2 + HEIGHT / 2;
	if (draw.start < 0)
		draw.start = 0;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT - 1;
	draw.y = draw.start;
	while (draw.y < draw.end)
	{
		tex_y = ((draw.y - draw.start) * tex.height) / line_height;
		draw.color = draw.data[tex_y * tex.width + tex_x];
		draw.color = apply_shading(draw.color, ray);
		my_mlx_pixel_put(&game->img, x, draw.y, draw.color);
		draw.y++;
	}
}

bool	raycast(t_game *game, char **map, t_player *player, t_data *img)
{
	int		x;
	t_ray	ray;
	int		line_height;

	if (!map)
		return (false);
	x = 0;
	while (x < WIDTH)
	{
		ray.camera_x = 2 * x / (double)WIDTH - 1;
		ray.dir.x = player->dir.x + player->plane.x * ray.camera_x;
		ray.dir.y = player->dir.y + player->plane.y * ray.camera_x;
		ray.map_x = (int)player->pos.x;
		ray.map_y = (int)player->pos.y;
		ray_calculate_delta(&ray);
		ray_step(&ray, player);
		ray_dda(game, &ray, map, img);
		ray.perp_wall_dist = get_distance(&ray, player);
		get_wall_x(&ray, player);
		line_height = (int)(HEIGHT / ray.perp_wall_dist);
		draw_vertical_line(game, line_height, x, &ray);
		x++;
	}
	return (true);
}
