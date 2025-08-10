/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 07:14:27 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/10 15:29:50 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	fill(t_map *map, char **data)
{
	int		i;

	i = 0;
	while (data[i])
	{
		if (ft_strnstr(data[i], "NO", ft_strlen(data[i])))
			map->north_texture_path = ft_strdup(ft_strnstr(data[i], "NO",
											ft_strlen(data[i])));
		else if (ft_strnstr(data[i], "SO", ft_strlen(data[i])))
			map->south_texture_path = ft_strdup(ft_strnstr(data[i], "SO",
											ft_strlen(data[i])));
		else if (ft_strnstr(data[i], "WE", ft_strlen(data[i])))
			map->west_texture_path = ft_strdup(ft_strnstr(data[i], "WE",
											ft_strlen(data[i])));
		else if (ft_strnstr(data[i], "EA", ft_strlen(data[i])))
			map->east_texture_path = ft_strdup(ft_strnstr(data[i], "EA",
											ft_strlen(data[i])));
		i++;
	}
}

static void	trim_blanks(t_map *map)
{
	char	*temp;

	if (!map->north_texture_path || !map->south_texture_path
		|| !map->east_texture_path || !map->west_texture_path)
		return ;
	temp = ft_strtrim(map->north_texture_path, " \n\t\v\f\r");
	free(map->north_texture_path);
	map->north_texture_path = temp;
	temp = ft_strtrim(map->south_texture_path, " \n\t\v\f\r");
	free(map->south_texture_path);
	map->south_texture_path = temp;
	temp = ft_strtrim(map->east_texture_path, " \n\t\v\f\r");
	free(map->east_texture_path);
	map->east_texture_path = temp;
	temp = ft_strtrim(map->west_texture_path, " \n\t\v\f\r");
	free(map->west_texture_path);
	map->west_texture_path = temp;
}

static char	**get_trimmed_map(char **map)
{
	char	**result;
	int		i;
	char	*line;

	result = NULL;
	i = 0;
	while (map[i])
	{
		line = ft_strtrim(map[i], "\n\t\v\f\r");
		if (!line)
		{
			free_all(result);
			return (NULL);
		}
		result = get_swords(result, line);
		if (!result)
		{
			free(line);
			return (NULL);
		}
		free(line);
		i++;
	}
	return (result);
}

static void	add_map(t_map *map, char **data)
{
	int		i;
	char	**result;

	result = NULL;
	i = 0;
	while (data[i])
	{
		if (ft_strnstr(data[i], "111", ft_strlen(data[i])))
		{
			while (data[i])
			{
				result = get_swords(result, data[i]);
				if (!result)
					return ;
				i++;
			}
		}
		if (!data[i])
			break ;
		i++;
	}
	map->grid = get_trimmed_map(result);
	free_all(result);
}

t_map	*get_filled_t_map(char *filename)
{
	t_map	*map;
	char	**data;

	map = get_initialized_map();
	if (!map)
		return (NULL);
	data = get_file_data(filename);
	if (!data)
	{
		free(map);
		return (NULL);
	}
	fill(map, data);
	trim_blanks(map);
	add_map(map, data);
	free_all(data);
	if (map->ceiling_color == -1 || map->floor_color == -1
		|| !map->north_texture_path || !map->south_texture_path
		|| !map->east_texture_path || !map->west_texture_path || !map->grid)
	{
		free_t_map(map);
		return (NULL);
	}
	return (map);
}
