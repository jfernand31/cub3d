#include "cub3D.h"

void	error_message(int type)
{
	if (type == ARGS)
		write (2, "Error\nArguments are invalid\n", 28);
	else if (type == FILE)
		write (2, "Error\nFile is invalid\n", 22);
	else if (type == MAP)
		write (2, "Error\nMap is invalid\n", 21);
	else if (type == MALLOC)
		write (2, "Error\nMalloc failed\n", 20);
	return ;
}
