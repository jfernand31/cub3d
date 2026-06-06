#include "cub3D.h"
#include <fcntl.h>

void	load_map(char *map_file, t_game *game)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return ;
}
