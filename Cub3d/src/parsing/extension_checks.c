/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-enca <mda-enca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 12:31:06 by mda-enca          #+#    #+#             */
/*   Updated: 2026/07/09 12:31:07 by mda-enca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*
	Check if there's a .xpm extension in the texture files.
*/

int	check_xpm_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 5)
		return (-1);
	if (ft_strncmp((path + len - 4), ".xpm", 4) != 0)
		return (-1);
	return (0);
}

/*
	Check for the .cub extension.
*/

int	check_extension(char *file)
{
	char	*cub_extension;
	char	*extension;
	char	*no_path;

	cub_extension = ".cub";
	extension = file + (ft_strlen(file) - 4);
	no_path = remove_path(file);
	if (ft_strncmp(cub_extension, extension, 4) != 0)
		return (-1);
	if (ft_strcmp(no_path, ".cub") == 0)
		return (-1);
	return (0);
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
