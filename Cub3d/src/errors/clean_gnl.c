#include "cub3D.h"

void	clean_gnl(t_game *game, int fd)
{
	finish_reading(fd);
	free_game(game);
	exit(1);
}

void	finish_reading(int fd)
{
	char *line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
