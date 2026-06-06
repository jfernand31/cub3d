#include <stdlib.h>
#include <unistd.h>
#include "cub3D.h"
#include "libft.h"

void	init_game(t_game *game)
{
	game->map = NULL;
	game->player.pos.x = 2.0;
	game->player.pos.y = 2.0;
	game->player.dir.x = 1.0;
	game->player.dir.y = 0.4;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.66;
	game->map_w = 0;
	game->map_h = 0;
	game->ceiling_color = 0x0000FF00;
	game->floor_color = 0x000000FF;
	game->keys.w = false;
	game->keys.a = false;
	game->keys.s = false;
	game->keys.d = false;
	game->keys.left = false;
	game->keys.right = false;
}

void	rude_parse_map(char *file, t_game *game)
{
	if (!file)
		return ;

	int fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	
	int	i = 0;
	char	*line = get_next_line(fd);
	game->map_w = ft_strlen(line);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	game->map_h = i;
	game->map = (char **)ft_calloc(game->map_h + 1, sizeof(char *));
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		line[ft_strlen(line) - 1] = '\0';
		game->map[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_next_line(fd);
	}	
	game->map[i] = NULL;
}


void	free_game(t_game *game)
{
	
	if (game->map)
	{
		int i = 0;
		while (i < game->map_h)
		{
			free(game->map[i]);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_game	game;

	if(argc != 2)
	{
		ft_printf("Usage is: ./cub3D <map.cub>\n");
		return (1);
	}
	check_extension(av[1]);
	init_game(&game);
	rude_parse_map(argv[1], &game);
	if (!game.map)
		return (1);
	if (!run_game(&game))
	{
		free_game(&game);
		return (1);
	}
	free_game(&game);
	return (0);
}
