#include "cub3D.h"
#include <fcntl.h>
/*
	Detects the texture identifier and stores the matching path.
*/
int	texture_parser(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 && space_check(line[2]))
		return (assign_path(line, &game->textures.no_path));
	if (ft_strncmp(line, "SO", 2) == 0 && space_check(line[2]))
		return (assign_path(line, &game->textures.so_path));
	if (ft_strncmp(line, "EA", 2) == 0 && space_check(line[2]))
		return (assign_path(line, &game->textures.ea_path));
	if (ft_strncmp(line, "WE", 2) == 0 && space_check(line[2]))
		return (assign_path(line, &game->textures.we_path));
	else
		return (-1); //error needs handling. unknown texture.
}

/*
	Validates and assigns the texture path.
*/
int	assign_path(char *line, char **path)
{
	char	*parsed_line;

	if (!*path)
	{
		parsed_line = extract_path(line);
		if (!parsed_line)
			return (-1);
		if (valid_path(parsed_line) == -1)
		{
			free(parsed_line);
			return (-1);
		}
		*path = ft_strdup(parsed_line);
		free(parsed_line);
		if (!*path)
			return (-1);
		return (0);
	}
	return (-1); //error needs handling. cant duplicate texture.
}


/*
	Checks if its a valid .xpm path.
*/

int	valid_path(char *path)
{
	int		fd;

	if (!path || path[0] == '\0')
		return (-1);
	if (check_xpm_extension(path) == -1)
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}

/*
	Extract path.
*/

char *extract_path(char *line)
{
	char *path;

	path = line + 2;
	if (space_check(*path) == 0)
		return (NULL); //error needs handling. 
	path = ft_strtrim(path, " \r\t\n\v\f");
	if (!path)
		return (NULL); //error needs handling.
	return (path);
}
