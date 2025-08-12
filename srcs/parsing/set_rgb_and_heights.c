/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb_and_heights.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 06:46:42 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/12 14:39:16 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_map_height(t_map *map)
{
	int	i;

	i = 0;
	if (!map->grid || !map)
		return ;
	while (map->grid[i])
		i++;
	map->map_height = i;
}

static void	set_map_width(t_map *map)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!map->grid || !map)
		return ;
	while (map->grid[i])
	{
		if (len < (int) ft_strlen(map->grid[i]))
			len = (int) ft_strlen(map->grid[i]);
		i++;
	}
	map->map_width = len;
}

static int	get_rgb_val(char **data, char *key)
{
	char	*line;
	int		i;
	char	*temp;

	i = 0;
	line = NULL;
	while (data[i])
	{
		if (ft_strnstr(data[i], &key[8], ft_strlen(data[i])))
			line = data[i];
		i++;
	}
	if (!line)
		return (-1);
	temp = ft_strtrim(line, key);
	if (!temp)
		return (-1);
	i = get_color_from_rgb(temp);
	free(temp);
	return (i);
}

void	set_rgb_and_heights(t_map *map, char **data)
{
	if (!map | !data)
		return ;
	set_map_height(map);
	set_map_width(map);
	map->floor_color = get_rgb_val(data, " \n\f\v\r\t. F");
	if (map->floor_color == -1)
	{
		print_null("No floor color!");
		return ;
	}
	map->ceiling_color = get_rgb_val(data, " \n\f\v\r\t. C");
	if (map->ceiling_color == -1)
	{
		print_null("No ceiling color!");
		return ;
	}
}
