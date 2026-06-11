#include "cub3D.h"
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
		ray->side_dist.x = (ray->map_x + 1.0 - player->pos.x) *ray->delta_dist.x;
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
		ray->side_dist.y = (ray->map_y + 1.0 - player->pos.y) *ray->delta_dist.y;
	}	
}

void	ray_step(t_ray *ray, t_player *player)
{
	ray_step_x(ray, player);
	ray_step_y(ray, player);
}

void	ray_dda(t_ray *ray, char **map, t_data *img)
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
		if (map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
	draw_square_pixel(img,
    		ray->map_x * MINIMAP_SCALE,
		ray->map_y * MINIMAP_SCALE,
		0xFF0000);
}

void	ray_calculate_delta(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->delta_dist.x = 1000000000;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = 1000000000;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

void	draw_vertical_line(t_data *img, int x, int line_height, t_ray *ray)
{
	int	draw_start;
	int	draw_end;
	int	y;
	int	shade;
	int	color;

	shade = 255 / (1 + ray->perp_wall_dist * 0.1);
	color = (shade << 16) | (shade << 8) | shade;
	draw_end = line_height / 2 + HEIGHT / 2;
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	y = draw_start;
	while (y < draw_end)
	{
		my_mlx_pixel_put(img, x, y, color);
		y++;
	}
}

bool	raycast(char **map, t_player *player, t_data *img)
{
	if (!map)
		return (false);
	t_ray	ray;

	int x = 0;

	while(x < WIDTH)
	{
		ray.camera_x = 2 * x / (double)WIDTH - 1;

		ray.dir.x = player->dir.x + player->plane.x * ray.camera_x;
		ray.dir.y = player->dir.y + player->plane.y * ray.camera_x;
		ray.map_x = (int)player->pos.x;
		ray.map_y = (int)player->pos.y;
		ray_calculate_delta(&ray);
		ray_step(&ray, player);
		ray_dda(&ray, map, img);
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.map_x - player->pos.x + (1 - ray.step_x)/ 2) / ray.dir.x;
		else
			ray.perp_wall_dist = (ray.map_y - player->pos.y + (1 - ray.step_y) / 2) / ray.dir.y;
		int line_height = (int)(HEIGHT / ray.perp_wall_dist);
		draw_vertical_line(img, x, line_height, &ray);
		x++;
	}

	return (true);
}

