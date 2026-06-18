#ifndef CUB3D_H
# define CUB3D_H
# include <stdbool.h>
#include  <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <X11/keysym.h>
#include <X11/X.h>

#include "../libs/libft/src/get_next_line/get_next_line.h"
#include "../libs/minilibx-linux/mlx.h"
#include "../libs/libft/src/ft_printf/ft_printf.h"
#include "../libs/libft/include/libft.h"

#define MINIMAP_SCALE 8
#define TILE_SIZE	  32
#define WIDTH		  1920
#define HEIGHT	      1080
#define KEY_W         119
#define KEY_A         97
#define KEY_S         115
#define KEY_D		  100
#define KEY_LEFT	  65361
#define KEY_RIGHT	  65363
#define KEY_ESC		  65307

//Errors
# define ARGS		  918
# define FILE	      919
# define MAP          920
# define MALLOC       921


typedef struct s_keys
{
	bool		w;
	bool		a;
	bool		s;
	bool		d;
	bool		left;
	bool		right;
}	t_keys;

typedef struct s_vec2
{
	double		x;
	double		y;
}	t_vec2;

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_data;

typedef struct s_player
{
	t_vec2		pos;
	t_vec2		dir;
	t_vec2		plane;
}	t_player;

typedef struct s_ray
{
	double		camera_x;
	t_vec2		dir;
	int			map_x;
	int			map_y;
	t_vec2		delta_dist;
	t_vec2		side_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		perp_wall_dist;
}	t_ray;

typedef struct	s_textures
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
} t_textures;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_data		img;
	t_player	player;
	char		**map;
	int			map_w;
	int			map_h;
	t_ray		ray;
	int			floor_color;
	int			floor_set;
	int			ceiling_color;
	int			ceiling_set;
	t_keys		keys;
	t_textures	textures;
}	t_game;

//utils
t_vec2	vec2_mult(t_vec2 v, float n);

//game
bool	run_game(t_game *game);

//cleanup
void	free_game(t_game *game);

//events
int		handle_key_release(int keycode, t_game *game);
int		handle_key_press(int keycode, t_game *game);
int		close_game(t_game *game);

//render
void	draw_floor_ceiling(t_data *img, int floor, int ceiling);
void	draw_player(t_data *img, t_player *player);
void	draw_minimap(t_data *img, char **map, t_game *game);
void	draw_square(t_data *img, int x, int y, int color);
void	draw_square_pixel(t_data *img, int x, int y, int color);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		render(void *param);

//raycast
bool	raycast(char **map, t_player *player, t_data *img);

//movement
void	update_player(t_game *game);
void	player_movement(t_game *game, t_keys keys);
void	player_rotate(t_player *player, t_keys keys);

//errors and free
int		error_exit(t_game *game, int type);
void	free_map(char **map, int map_h);
void	error_message(int type);
void	free_textures(t_textures *textures);
void	free_game(t_game *game);
void	clean_gnl(t_game *game, int fd);
void	finish_reading(int fd);

//parsing
int		check_xpm_extension(char *path);
int		check_extension(char *file);
int		parsing(char *map_file, t_game *game);
int		parse_line(t_game *game, char *line, int fd);
int		line_type(t_game *game, char *line, int fd);
int		check_elements(t_game *game);
int		valid_line(const char *line);

//textures parsing
int		texture_parser(t_game *game, char *line);
int		assign_path(char *line, char **path);
int		valid_path(char *line);
char	*extract_path(char *line);

//Color parsing
int		color_parser(t_game *game, char *line);
int		parse_rgb(char *line);
int		rgb_value(char **line);
int		comma_check(char **line);

//Map parsing
int		parser_map(t_game *game, int fd, char *first_row);
int		add_line(t_list **map_list, char *line, t_game *game);
char	*replace_spaces(char *line);
int		read_all(int fd, t_list **map, t_game *game);
int		copy_list(t_game *game, t_list *list);
void	normalize_map(char *dest, char *src, int w);

//Map validation
int		validate_map(t_game *game);
void	set_start(t_game *game, int y, int x);
void	set_direction(t_game *game, int y, int x);
int		walkable_check(char c);
int		surrounding_check(t_game *game, int y, int x);

//Parsing utils
int		ft_strcmp(char *s1, char *s2);
char	*remove_path(char *file);
int		space_check(char c);
int		skip_whitespaces(char *line);
void	skip_whitespaces_ptr(char **line);
int		max_width(int a, int b);

#endif

