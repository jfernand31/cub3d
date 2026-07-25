#include "../../include/cub3D.h"
#include <float.h>
#include <math.h>

void	ray_step_x(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->step_x = -1;
		ray->side_dist.x = (player->pos.x - ray->map_x) * ray->delta_dist.x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist.x = (ray->map_x + 1.0 - player->pos.x)
			* ray->delta_dist.x;
	}
}

void	ray_step_y(t_ray *ray, t_player *player)
{
	if (ray->dir.y < 0)
	{
		ray->step_y = -1;
		ray->side_dist.y = (player->pos.y - ray->map_y) * ray->delta_dist.y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist.y = (ray->map_y + 1.0 - player->pos.y)
			* ray->delta_dist.y;
	}
}

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
		if (ray->map_x < 0 || ray->map_x >= g->map_w || ray->map_y < 0
			|| ray->map_y >= g->map_h)
			break ;
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	if (ray->hit)
		draw_square_pixel(img, ray->map_x * MINIMAP_SCALE,
			ray->map_y * MINIMAP_SCALE, 0xFF0000);
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
