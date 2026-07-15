/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 19:36:15 by jfernand          #+#    #+#             */
/*   Updated: 2026/07/06 19:37:06 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <stdlib.h>

int	close_game(t_game *game)
{
	free_game(game);
	exit(0);
}

int	handle_key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->keys.w = false;
	if (keycode == KEY_S)
		game->keys.s = false;
	if (keycode == KEY_D)
		game->keys.d = false;
	if (keycode == KEY_A)
		game->keys.a = false;
	if (keycode == KEY_LEFT)
		game->keys.left = false;
	if (keycode == KEY_RIGHT)
		game->keys.right = false;
	return (0);
}

int	handle_key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		free_game(game);
		exit(0);
	}
	if (keycode == KEY_W)
		game->keys.w = true;
	if (keycode == KEY_S)
		game->keys.s = true;
	if (keycode == KEY_D)
		game->keys.d = true;
	if (keycode == KEY_A)
		game->keys.a = true;
	if (keycode == KEY_LEFT)
		game->keys.left = true;
	if (keycode == KEY_RIGHT)
		game->keys.right = true;
	return (0);
}
