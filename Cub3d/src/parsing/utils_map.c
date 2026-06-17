
#include "cub3D.h"

int	max_width(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	normalize_map(char *dest, char *src, int w)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < w)
	{
		dest[i] = 'X';
		i++;
	}
	dest[i] = '\0';
}
