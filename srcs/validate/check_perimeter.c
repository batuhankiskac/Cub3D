/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_perimeter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:27:24 by bkiskac           #+#    #+#             */
/*   Updated: 2025/10/14 22:35:20 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int is_exposed(t_map *map, int y, int x)
{
	if (y == 0 || y == map->map_height - 1 || x == 0)
		return (1);
	if (x >= (int)ft_strlen(map->grid[y - 1])
		|| x >= (int)ft_strlen(map->grid[y + 1]))
		return (1);
	if (map->grid[y - 1][x] == ' ' || map->grid[y + 1][x] == ' '
		|| map->grid[y][x - 1] == ' ' || map->grid[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	check_perimeter(t_map *map)
{
	int	y;
	int	x;
	int	row_len;

	y = -1;
	while (++y < map->map_height)
	{
		x = -1;
		row_len = ft_strlen(map->grid[y]);
		while (++x < row_len)
		{
			if (ft_strchr("0NSEW", map->grid[y][x]))
			{
				if (is_exposed(map, y, x))
					return (print_error("Map is not properly enclosed by walls",
							ERROR));
			}
		}
	}
	return (0);
}
