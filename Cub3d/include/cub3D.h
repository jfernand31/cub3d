#ifndef CUB3D_H
# define CUB3D_H

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_player
{
	t_vec2	pos;
}	t_player;

typedef struct	s_game
{
	t_player	player;
	char		**map;
}	t_game;

#endif

