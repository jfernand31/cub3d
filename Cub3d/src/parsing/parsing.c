#include "cub3D.h"
#include <fcntl.h>

/*
	Opens the .cub file and starts it's parsing.
	Checks if all the elements exist.
*/

void	parsing(char *map_file, t_game *game)
{
	int	fd;
	char *line;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		return ;
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return ; // error needs handling. file empty.
	}
	parse_line(game, line, fd);
	close(fd);
	if (check_elements(game))
		return ;//error needs handling. missing elements.
	return ;
}

/*
	Reads the file line by line until it finds the map or an error.
*/

void	parse_line(t_game *game, char *line, int fd)
{
	char	*parsed_line;
	int		ret;

	while (line)
	{
		parsed_line = ft_strtrim(line, "\n\r");
		free(line);
		ret = line_type(game, parsed_line, fd);
		if (ret)
		{
			if (ret == -1)
				return ;//clean remaining gnl buffer and stop
			free(parsed_line);
			break ;
		}
		else
		{
			free(parsed_line);
			line = get_next_line(fd);
		}
	}
}

/*
	Detects what type of line was read and redirects it to the correct parser.
*/

int		line_type(t_game *game, char *line, int fd)
{
	int	i;

	i = skip_whitespaces(line);
	if (i == -1 || !line[i])
		return (0);
	if (ft_strchr("FC", line[i]))
		color_parser(game, line + i); //missing
	else if (ft_strchr("NSWE", line[i]))
		texture_parser(game, line + i); //missing
	else if (line[i] == '1')
	{
		if (check_elements(game))
			return (-1); //error needs handling. map has to be the last element.
		if (!valid_line(line))
			return (-1);
		if (!parser_map(game, fd, line))
			return (-1);
	}
	return (0);
}

/*
	Checks whether any texture or color element is missing. 
*/

int	check_elements(t_game *game)
{
	if (!game->ceiling_color)
		return (1);
	else if (!game->floor_color)
		return (1);
	else if(!game->textures.ea_path)
			return (1);
	else if(!game->textures.we_path)
			return (1);
	else if(!game->textures.so_path)
			return (1);
	else if(!game->textures.no_path)
			return (1);
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
		return (1);
	while (line[i])
	{
		if (!ft_strchr(" 01NSWE", line[i]))
			return (1);
		if (ft_strchr("01NSWE", line[i]))
			element_found = 1;
		i++;
	}
	if (element_found == 0)
		return (1);
	return (0);
}
