#include "cub3D.h"

void	check_extension(char *file)
{
	char	*cub_extension;
	char	*extension;
	char	*no_path;

	cub_extension = ".cub";
	extension = file + (ft_strlen(file) - 4);
	no_path = remove_path(file);
	if (ft_strncmp(cub_extension,extension, 4) != 0)
		return ;//error ARGS;
	if (ft_strcmp(no_path, ".cub") == 0)
		return ;//error ARGS;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*remove_path(char *file)
{
	int		i;

	i = 0;
	while (file[i])
		i++;
	i -= 1;
	while (file[i] != '/' && i >= 0)
		i--;
	i += 1;
	return (file + i);
}
