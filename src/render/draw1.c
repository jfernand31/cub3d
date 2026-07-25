#include "../../include/cub3D.h"

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
