#include "cub3D.h"

int	parser_map(t_game *game, int fd, char *first_line)
{
	t_list	*map_list;

	map_list = NULL;
	game->map_w = 0;
	if (add_line(&map_list, first_line, game) == -1)
		return (-1); //error needs handling.
	if (read_all(fd, &map_list, game) == -1)
		return (ft_lstclear(&map_list, free), -1); //error needs handling.
	game->map_h = ft_lstsize(map_list);
	if (copy_list(game, map_list) == -1)
		return (ft_lstclear(&map_list, free), -1); //error needs handling.
	ft_lstclear(&map_list, free);
	if (validate_map(game) == -1)
		return (-1); //error needs handling.
	return (0);
}

int	add_line(t_list **map_list, char *line, t_game *game)
{
	char	*parsed_line;
	t_list	*new_node;

	parsed_line = replace_spaces(line);
	free(line);
	if (!parsed_line)
		return (-1);
	if (parsed_line[0] == '\0')
	{
		ft_lstclear(map_list, free);
		return (free(parsed_line), -1); //error needs handling.
	}
	new_node = ft_lstnew(parsed_line);
	if (!new_node)
	{
		ft_lstclear(map_list, free);
		return (free(parsed_line), -1); //error needs handling.
	}
	ft_lstadd_back(map_list, new_node);
	game->map_w = max_width(game->map_w, (int)ft_strlen(parsed_line));
	return (0);
}

char	*replace_spaces(char *line)
{
	int		i;
	char	*trimmed;
	char	*res;

	i = 0;
	trimmed = ft_strtrim(line, "\n\r");
	if (!trimmed)
		return (NULL);
	res = (char *)malloc(ft_strlen(trimmed) + 1);
	if (!res)
		return (free(trimmed), NULL); //error needs handling.
	while (trimmed[i] != '\0')
	{
		if (trimmed[i] == ' ')
			res[i] = 'X';
		else
			res[i] = trimmed[i];
		i++;
	}
	res[i] = '\0';
	free(trimmed);
	return (res);
}

int	read_all(int fd, t_list **map, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (add_line(map, line, game) == -1)
			return (-1); //error needs handling.
		line = get_next_line(fd);
	}
	return (0);
}

int	copy_list(t_game *game, t_list *list)
{
	t_list	*node;
	int		y;

	y = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->map_h + 1));
	if (!game->map)
		return (-1); //error needs handling.
	node = list;
	while (node)
	{
		game->map[y] = (char *)malloc(sizeof(char) * (game->map_w + 1));
		if (!game->map[y])
		{
			while (y > 0)
				free(game->map[--y]);
			free(game->map);
			return (-1);
		}
		normalize_map(game->map[y], (char *)node->content, game->map_w);
		y++;
		node = node->next;
	}
	game->map[y] = NULL;
	return (0);
}
