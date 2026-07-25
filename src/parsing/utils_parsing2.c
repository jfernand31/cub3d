#include "../../include/cub3D.h"

int	map_space_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
			return (1);
		if (line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (0);
}
