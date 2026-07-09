/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:31:22 by mda-enca          #+#    #+#             */
/*   Updated: 2026/07/09 12:31:23 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	space_check(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
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

void	skip_whitespaces_ptr(char **line)
{
	int	i;

	i = skip_whitespaces(*line);
	if (i > 0)
		*line += i;
}

int	read_empty_line(int fd, char *line)
{
	while (line)
	{
		if (skip_whitespaces(line) != -1)
		{
			free(line);
			finish_reading(fd);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

int	handle_line_result(int ret, char *parsed_line, int fd)
{
	if (ret <= 0)
		return (0);
	if (ret < 0)
	{
		if (ret == -1)
			free(parsed_line);
		finish_reading(fd);
		return (-1);
	}
	return (1);
}
