/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:55:48 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/06 15:57:33 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture_files(t_map *map)
{
	int		fd;
	int		i;
	int		len;
	char	*paths[4];

	paths[0] = map->north_texture_path;
	paths[1] = map->south_texture_path;
	paths[2] = map->west_texture_path;
	paths[3] = map->east_texture_path;
	i = -1;
	while (++i < 4)
	{
		len = ft_strlen(paths[i]);
		if (len < 5 || ft_strcmp(&paths[i][len - 4], ".xpm") != 0)
			return (print_error("Texture file must have .xpm extension",
					ERROR));
		fd = open(paths[i], O_RDONLY);
		if (fd == -1)
			return (print_error("Cannot open one of the texture files", ERROR));
		close(fd);
	}
	return (0);
}

static int	check_elements_parsed(t_map *map)
{
	if (!map->north_texture_path || !map->south_texture_path
		|| !map->west_texture_path || !map->east_texture_path)
		return (print_error("Map: Missing one or more texture paths.", ERROR));
	if (map->floor_color == -1 || map->ceiling_color == -1)
		return (print_error("Map: Missing or invalid floor/ceiling color.",
				ERROR));
	return (0);
}

int	validate_elements(t_map *map)
{
	if (check_elements_parsed(map) == ERROR)
		return (ERROR);
	if (check_texture_files(map) == ERROR)
		return (ERROR);
	return (0);
}
