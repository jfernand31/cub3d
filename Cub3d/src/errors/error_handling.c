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

int	error_exit(t_game *game, int type)
{
	error_message(type);
	free_game(game);
	return (-1);
}
