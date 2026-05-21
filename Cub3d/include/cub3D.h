#ifndef CUB3D_H
# define CUB3D_H
# include <stdbool.h>

#define TILE_SIZE 32

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
}	t_player;

typedef struct s_ray
{
	double	camera_x;
	t_vec2	dir;
	int	map_x;
	int	map_y;
	t_vec2	delta_dist;
	t_vec2	side_dist;
	int	step_x;
	int	step_y;
	int	hit;
	int	side;
	double	perp_wall_dist;
}	t_ray;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_player	player;
	char		**map;
	int		map_w;
	int		map_h;
	t_ray		ray;
}	t_game;

bool	run_game(t_game *game);

#endif

