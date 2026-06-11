#include "cub3D.h"

int	space_check(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
		c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

/*
	Skip whitespaces.
*/

int	skip_whitespaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (space_check(line[i]) == 1)
			i++;
		else
			return (i);
	}
	return (-1);
}
