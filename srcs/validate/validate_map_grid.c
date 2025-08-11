/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:28:06 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/11 13:34:15 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_content(t_map *map)
{
	int y;
	int x;
	int player_count;

	y = -1;
	player_count = 0;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (!ft_strchr(" 01NSEW", map->grid[y][x]))
				return (print_error("Invalid character in map", ERROR));
			if (ft_strchr("NSEW", map->grid[y][x]))
				player_count++;
		}
	}
	if (player_count != 1)
		return (print_error("Map must contain exactly one player", ERROR));
	return (0);
}

int	validate_map_grid(t_map *map)
{
	if (!map->grid || !map->grid[0])
		return (print_error("Map grid not found", ERROR));
	if (check_content(map) == ERROR)
		return (ERROR);
	if (execute_fill(map) == ERROR)
		return (ERROR);
	return (0);
}
