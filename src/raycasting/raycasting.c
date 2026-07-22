 #include "cub3D.h"
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
		ray->side_dist.x = (ray->map_x + 1.0 - player->pos.x) * ray->delta_dist.x;
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
		ray->side_dist.y = (ray->map_y + 1.0 - player->pos.y) * ray->delta_dist.y;
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
	int		draw_start;
	t_draw		draw;
	t_texture	tex;

	tex = check_wall(game, ray);
	draw.data = (int *)tex.addr;
	draw.tex_x = (int)(ray->wall_x * tex.width);
	if (draw.tex_x >= tex.width)
		draw.tex_x = tex.width - 1;
	if (ray->side == 0 && ray->dir.x < 0)
		draw.tex_x = tex.width - draw.tex_x - 1;
	if (ray->side == 1 && ray->dir.y > 0)
		draw.tex_x = tex.width - draw.tex_x - 1;
	draw.start = -line_height / 2 + HEIGHT / 2;
	draw.end = line_height / 2 + HEIGHT / 2;
	draw_start = draw.start;
	step = (double)tex.height / (double)line_height;
	if (draw.start < 0)
		draw.start = 0;
	tex_pos = (draw.start - draw_start) * step;
	if (draw.end >= HEIGHT)
		draw.end = HEIGHT - 1;
	draw.y = draw.start;
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
 
static double	get_distance(t_ray *r, t_player *p)
{
	if (r->side == 0)
		return ((r->map_x - p->pos.x + (1 - r->step_x) / 2) / r->dir.x);
	return ((r->map_y - p->pos.y + (1 - r->step_y) / 2) / r->dir.y);
 }
 
static void	get_wall_x(t_ray *r, t_player *p)
{
	if (r->side == 0)
		r->wall_x = p->pos.y + r->perp_wall_dist * r->dir.y;
	else
		r->wall_x = p->pos.x + r->perp_wall_dist * r->dir.x;
	r->wall_x -= floor(r->wall_x);
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
		if (ray.hit)
		{
			ray.perp_wall_dist = get_distance(&ray, player);
			get_wall_x(&ray, player);
			line_height = (int)(HEIGHT / ray.perp_wall_dist);
			draw_vertical_line(game, line_height, x, &ray);
		}
		x++;
	}
	return (true);
}

