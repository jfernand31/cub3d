#include "cub3D.h"
#include <math.h>

t_vec2	vec2_mult(t_vec2 v, float n)
{
	return ((t_vec2){v.x * n, v.y * n});
}

static void	try_move(t_game *g, t_vec2 move)
{
	t_player	*p;

	p = &g->player;
	if (g->map[(int)p->pos.y][(int)(p->pos.x + move.x)] != '1')
		p->pos.x += move.x;
	if (g->map[(int)(p->pos.y + move.y)][(int)p->pos.x] != '1')
		p->pos.y += move.y;
}

void	rotate(t_vec2 *vec, float rot)
{
	float	old_vec_x;
	float	c;
	float	s;

	c = cos(rot);
	s = sin(rot);
	old_vec_x = vec->x;
	vec->x = vec->x * c - vec->y * s;
	vec->y = old_vec_x * s + vec->y * c;
}


void	player_rotate(t_player *player, int keycode)
{
	const float	rot = 0.05;

	if (keycode == KEY_RIGHT)
	{
		rotate(&player->dir, rot);
		rotate(&player->plane, rot);
	}
	if (keycode == KEY_LEFT)
	{
		rotate(&player->dir, -rot);
		rotate(&player->plane, -rot);
	}
}

void	player_movement(t_game *game, int keycode)
{
	const float	speed = 0.05;
	t_vec2		move;

	move = (t_vec2){0,0};
	if (keycode == KEY_W)
		move = vec2_mult(game->player.dir, speed);
	if (keycode == KEY_S)
		move = vec2_mult(game->player.dir, -speed);
	if (keycode == KEY_D)
		move = vec2_mult(game->player.plane, speed);
	if (keycode == KEY_A)
		move = vec2_mult(game->player.plane, -speed);
	try_move(game, move);
}
