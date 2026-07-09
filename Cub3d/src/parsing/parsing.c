/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:31:13 by mda-enca          #+#    #+#             */
/*   Updated: 2026/07/09 12:31:14 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <fcntl.h>

/*
	Opens the .cub file and starts it's parsing.
	Checks if all the elements exist.
*/

int	parsing(char *map_file, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (-1);
	}
	if (parse_line(game, line, fd) == -1)
		return (-1);
	close(fd);
	if (check_elements(game))
		return (-1);
	return (0);
}

/*
	Reads the file line by line until it finds the map or an error.
*/

int	parse_line(t_game *game, char *line, int fd)
{
	char	*parsed_line;
	int		ret;

	while (line)
	{
		parsed_line = ft_strtrim(line, "\t\v\f\n\r");
		free(line);
		ret = line_type(game, parsed_line, fd);
		ret = handle_line_result(ret, parsed_line, fd);
		if (ret == -1)
			return (-1);
		if (ret == 1)
			break ;
		free(parsed_line);
		line = get_next_line(fd);
	}
	return (0);
}

/*
	Detects what type of line was read and redirects it to the correct parser.
*/

int	line_type(t_game *game, char *line, int fd)
{
	int	i;

	i = skip_whitespaces(line);
	if (i == -1 || !line[i])
		return (0);
	if (ft_strchr("FC", line[i]))
	{
		return (color_parser(game, line + i));
	}
	else if (ft_strchr("NSWE", line[i]))
	{
		return (texture_parser(game, line + i));
	}
	else if (line[i] == '1')
	{
		if (check_elements(game) == -1)
			return (-1);
		if (valid_line(line) == -1)
			return (-1);
		if (parser_map(game, fd, line) == -1)
			return (-2);
		return (1);
	}
	return (-1);
}

/*
	Checks whether any texture or color element is missing. 
*/

int	check_elements(t_game *game)
{
	if (game->ceiling_set == 0)
		return (-1);
	else if (game->floor_set == 0)
		return (-1);
	else if (!game->textures.ea_path)
		return (-1);
	else if (!game->textures.we_path)
		return (-1);
	else if (!game->textures.so_path)
		return (-1);
	else if (!game->textures.no_path)
		return (-1);
	else
		return (0);
}

/*
	Checks if the line contains only valid map chars and has map content.
*/

int	valid_line(const char *line)
{
	int	i;
	int	element_found;

	i = 0;
	element_found = 0;
	if (!line || line[0] == '\0')
		return (-1);
	while (line[i])
	{
		if (!ft_strchr(" 01NSWE", line[i]))
			return (-1);
		if (ft_strchr("01NSWE", line[i]))
			element_found = 1;
		i++;
	}
	if (element_found == 0)
		return (-1);
	return (0);
}
