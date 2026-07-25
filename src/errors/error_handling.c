/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:32:09 by mda-enca          #+#    #+#             */
/*   Updated: 2026/07/09 12:32:10 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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
