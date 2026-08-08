/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 11:59:43 by mda-enca          #+#    #+#             */
/*   Updated: 2026/08/08 11:59:43 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	raycast(t_game *game, char **map, t_player *player)
{
	int		x;
	t_ray	ray;

	if (!map)
		return (false);
	x = 0;
	while (x < WIDTH)
	{
		process_ray(game, player, &ray, x);
		x++;
	}
	return (true);
}

t_texture	init_textures(t_game *game, t_ray *ray, t_draw *draw)
{
	t_texture	tex;

	tex = check_wall(game, ray);
	draw->data = (int *)tex.addr;
	draw->tex_x = (int)(ray->wall_x * tex.width);
	if (draw->tex_x >= tex.width)
		draw->tex_x = tex.width - 1;
	if (ray->side == 0 && ray->dir.x < 0)
		draw->tex_x = tex.width - draw->tex_x - 1;
	if (ray->side == 1 && ray->dir.y > 0)
		draw->tex_x = tex.width - draw->tex_x - 1;
	return (tex);
}

void	setup_draw(t_draw *draw, t_texture tex,
				int line_height, double *tex_pos)
{
	int	draw_start;

	draw->start = -line_height / 2 + HEIGHT / 2;
	draw->end = line_height / 2 + HEIGHT / 2;
	draw_start = draw->start;
	if (draw->start < 0)
		draw->start = 0;
	*tex_pos = (draw->start - draw_start)
		* ((double)tex.height / line_height);
	if (draw->end >= HEIGHT)
		draw->end = HEIGHT - 1;
	draw->y = draw->start;
}

void	process_ray(t_game *game, t_player *player,
				t_ray *ray, int x)
{
	int	line_height;

	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->dir.x = player->dir.x + player->plane.x * ray->camera_x;
	ray->dir.y = player->dir.y + player->plane.y * ray->camera_x;
	ray->map_x = (int)player->pos.x;
	ray->map_y = (int)player->pos.y;
	ray_calculate_delta(ray);
	ray_step(ray, player);
	ray_dda(game, ray, game->map, &game->img);
	if (ray->hit)
	{
		ray->perp_wall_dist = get_distance(ray, player);
		get_wall_x(ray, player);
		line_height = (int)(HEIGHT / ray->perp_wall_dist);
		draw_vertical_line(game, line_height, x, ray);
	}
}
