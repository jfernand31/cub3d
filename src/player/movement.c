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
	if (g->map[(int)p->pos.y][(int)(p->pos.x + move.x)] != '1'
		&& g->map[(int)p->pos.y][(int)(p->pos.x + move.x)] != 'X')
		p->pos.x += move.x;
	if (g->map[(int)(p->pos.y + move.y)][(int)p->pos.x] != '1'
		&& g->map[(int)(p->pos.y + move.y)][(int)p->pos.x] != 'X')
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

void	player_rotate(t_player *player, t_keys keys)
{
	const float	rot;

	rot = 0.03;
	if (keys.right)
	{
		rotate(&player->dir, rot);
		rotate(&player->plane, rot);
	}
	if (keys.left)
	{
		rotate(&player->dir, -rot);
		rotate(&player->plane, -rot);
	}
}

void	player_movement(t_game *game, t_keys keys)
{
	const float	speed;
	t_vec2		move;

	move = (t_vec2){0, 0};
	speed = 0.05;
	if (keys.w)
		move = vec2_mult(game->player.dir, speed);
	if (keys.s)
		move = vec2_mult(game->player.dir, -speed);
	if (keys.d)
		move = vec2_mult(game->player.plane, speed);
	if (keys.a)
		move = vec2_mult(game->player.plane, -speed);
	try_move(game, move);
}
