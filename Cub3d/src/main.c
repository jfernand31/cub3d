/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 11:58:13 by mda-enca          #+#    #+#             */
/*   Updated: 2026/07/09 12:29:54 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_game(t_game *game)
{
	game->player.pos.x = 2.0;
	game->player.pos.y = 2.0;
	game->player.dir.x = 1.0;
	game->player.dir.y = 0.4;
	game->player.plane.x = 0.0;
	game->player.plane.y = 0.66;
}

int	validate_input(char *file)
{
	int	fd;

	if (check_extension(file) == -1)
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (0);
}

int	load_game(char *file, t_game *game)
{
	if (parsing(file, game) == -1)
		return (error_exit(game, MAP));
	if (!game->map)
		return (error_exit(game, MAP));
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	if (argc != 2)
	{
		error_message(ARGS);
		return (1);
	}
	init_game(&game);
	if (validate_input(argv[1]) == -1)
		return (error_exit(&game, FILE), 1);
	if (load_game(argv[1], &game) == -1)
		return (error_exit(&game, MAP), 1);
	if (!run_game(&game))
	{
		free_game(&game);
		return (1);
	}
	free_game(&game);
	return (0);
}
