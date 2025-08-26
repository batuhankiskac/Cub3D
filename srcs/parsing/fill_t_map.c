/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_t_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 07:14:27 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/26 07:22:53 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*fill(t_map *map, char **data)
{
	int		i;

	i = 0;
	if (check_textures(data))
		return (print_null("All identifiers must be single."));
	while (data[i])
	{
		if (ft_strnstr(data[i], "NO", ft_strlen(data[i])))
			map->north_texture_path = ft_strdup(ft_strnstr(data[i], "NO",
						ft_strlen(data[i])) + 2);
		else if (ft_strnstr(data[i], "SO", ft_strlen(data[i])))
			map->south_texture_path = ft_strdup(ft_strnstr(data[i], "SO",
						ft_strlen(data[i])) + 2);
		else if (ft_strnstr(data[i], "WE", ft_strlen(data[i])))
			map->west_texture_path = ft_strdup(ft_strnstr(data[i], "WE",
						ft_strlen(data[i])) + 2);
		else if (ft_strnstr(data[i], "EA", ft_strlen(data[i])))
			map->east_texture_path = ft_strdup(ft_strnstr(data[i], "EA",
						ft_strlen(data[i])) + 2);
		i++;
	}
	if (!map->north_texture_path || !map->south_texture_path
		|| !map->east_texture_path || !map->west_texture_path)
		return (print_null("Error\ncub3D: Some texture ways couldn't find."));
	return (NULL);
}

static void	set_trimmed_ways(t_map *map)
{
	char	*line;

	line = NULL;
	if (map->north_texture_path)
		line = ft_strtrim(map->north_texture_path, " \n\f\v\r\t");
	free(map->north_texture_path);
	map->north_texture_path = line;
	line = NULL;
	if (map->south_texture_path)
		line = ft_strtrim(map->south_texture_path, " \n\f\v\r\t");
	free(map->south_texture_path);
	map->south_texture_path = line;
	line = NULL;
	if (map->west_texture_path)
		line = ft_strtrim(map->west_texture_path, " \n\f\v\r\t");
	free(map->west_texture_path);
	map->west_texture_path = line;
	line = NULL;
	if (map->east_texture_path)
		line = ft_strtrim(map->east_texture_path, " \n\f\v\r\t");
	free(map->east_texture_path);
	map->east_texture_path = line;
}

static char	**get_trimmed_map(char **map)
{
	char	**result;
	int		i;
	char	*line;

	result = NULL;
	i = 0;
	if (!map || !map[0])
		return (NULL);
	while (map[i])
	{
		line = ft_strtrim(map[i], "\n\t\v\f\r");
		if (!line)
		{
			free_all(result);
			return (NULL);
		}
		result = get_swords(result, line);
		free(line);
		if (!result)
			return (NULL);
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
		if (is_first_line_of_map(data, i))
		{
			while (data[i])
			{
				result = get_swords(result, data[i]);
				if (!result)
					break ;
				i++;
			}
		}
		if (!data[i])
			break ;
		i++;
	}
	map->grid = get_trimmed_map(result);
	if (!map->grid)
		print_null("No map in .cub file.");
	free_all(result);
}

t_map	*get_filled_t_map(char *filename)
{
	t_map	*map;
	char	**data;

	map = get_initialized_map();
	if (!map)
		return (print_null("Memory error"));
	data = get_file_data(filename);
	if (!data)
	{
		free(map);
		return (NULL);
	}
	fill(map, data);
	set_trimmed_ways(map);
	add_map(map, data);
	set_rgb_and_heights(map, data);
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
