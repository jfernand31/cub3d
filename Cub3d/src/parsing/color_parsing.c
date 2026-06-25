#include "cub3D.h"

int	color_parser(t_game *game, char *line)
{
	int	color;

	skip_whitespaces_ptr(&line);
	if (*line == 'F')
	{
		if (game->floor_set == '1')
			return (-1); //error needs handling. cant duplicate floor color.
		line++;
		skip_whitespaces_ptr(&line);
		color = parse_rgb(line);
		if (color == -1)
			return (-1);
		game->floor_color = color;
		game->floor_set = '1';
	}
	else if (*line == 'C')
	{
		if (game->ceiling_set == '1')
			return (-1); //error needs handling. cant duplicate ceiling color.
		line++;
		skip_whitespaces_ptr(&line);
		color = parse_rgb(line);
		if (color == -1)
			return (-1);
		game->ceiling_color = color;
		game->ceiling_set = '1';
	}
	else
		return (-1); //error needs handling. unknown color identifier.
	return (0);
}

int	parse_rgb(char *line)
{
	int	r;
	int	b;
	int	g;

	r = rgb_value(&line);
	if (r == -1 || comma_check(&line) == -1)
		return (-1);
	g = rgb_value(&line);
	if (g == -1 || comma_check(&line) == -1)
		return (-1);
	b = rgb_value(&line);
	if (b == -1) 
		return (-1);
	skip_whitespaces_ptr(&line);
	if (*line != '\0' && *line != '\n')
		return (-1); //error needs handling. characters after color.
	return ((r << 16) | (g << 8) | b);
}

int	rgb_value(char **line)
{
	int	value;

	skip_whitespaces_ptr(line);
	if (!ft_isdigit(**line))
		return (-1); //error needs handling. invalid color format.
	value = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	if (value < 0 || value > 255)
		return (-1); //error needs handling. value out of range.
	return (value);
}

int	comma_check(char **line)
{
	skip_whitespaces_ptr(line);
	if (**line != ',')
		return (-1); //error needs handling. invalid color format. comma missing.
	(*line)++;
	return (0);
}
