#include "cub3D.h"
#include <fcntl.h>
/*
	Detects the texture identifier and stores the matching path.
*/
int	texture_parser(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (assign_path(line, &game->textures.no_path));
	if (ft_strncmp(line, "SO", 2) == 0)
		return (assign_path(line, &game->textures.so_path));
	if (ft_strncmp(line, "EA", 2) == 0)
		return (assign_path(line, &game->textures.ea_path));
	if (ft_strncmp(line, "WE", 2) == 0)
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
		if (path_exists(line) == -1 || valid_path(line) == -1)
			return (-1); //error needs handling. path isn't valid.
		line += 2;
		if (space_check(*line) == 0)
			return (-1); //error needs handling. path isn't valid.
		parsed_line = ft_strtrim(line, " \t\r\n\v\f");
		if (!parsed_line)
			return (-1); //error needs handling. malloc failled.
		if (*parsed_line == '\0')
			return (-1); //error needs handling. Missing texture path. must free parsed line.
		*path = ft_strdup(parsed_line);
		free(parsed_line);
		if (!*path)
			return (-1);
		return (0);
	}
	return (-1); //error needs handling. cant duplicate texture.
}

/*
	Checks if path exists.
*/

int	path_exists(char *line)
{
	char	*path;
	char	*parsed_path;
	int		fd;

	path = line;
	while (*path && space_check(*path) == 0)
		path++;
	while (*path && space_check(*path) == 1)
		path++;
	parsed_path = ft_strtrim(line, " \t\r\n\v\f");
	if (!parsed_path)
		return (-1); //error needs handling. malloc error. must free parsed_path.
	fd = open(parsed_path, O_RDONLY);
	if (fd == -1)
		return (-1); //error needs handling. error opening fd.must free parsed_path.
	close(fd);
	free(parsed_path);
	return (0);
}

/*
	Checks if its a valid .xpm path.
*/

int	valid_path(char *line)
{
	char **splitted;
	
	if (ft_strchr(line, '.') == NULL)
		return (-1);

}
