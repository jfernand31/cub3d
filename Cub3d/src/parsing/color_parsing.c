#include "cub3D.h"

int	color_parser(t_game *game, char *line)
{
	skip_whitespaces_ptr(&line);
	if (*line == 'F')
		return (set_color(&game->floor_color,
				&game->floor_set, line));
	if (*line == 'C')
		return (set_color(&game->ceiling_color,
				&game->ceiling_set, line));
	return (-1);
}

int	set_color(int *dst_color, char *dst_set, char *line)
{
	int	color;

	if (*dst_set == '1')
		return (-1);
	line++;
	skip_whitespaces_ptr(&line);
	color = parse_rgb(line);
	if (color == -1)
		return (-1);
	*dst_color = color;
	*dst_set = '1';
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
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

int	rgb_value(char **line)
{
	int	value;

	skip_whitespaces_ptr(line);
	if (!ft_isdigit(**line))
		return (-1);
	value = ft_atoi(*line);
	while (ft_isdigit(**line))
		(*line)++;
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}

int	comma_check(char **line)
{
	skip_whitespaces_ptr(line);
	if (**line != ',')
		return (-1);
	(*line)++;
	return (0);
}
