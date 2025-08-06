/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:28:06 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/06 15:44:56 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_grid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W' || c == ' ');
}

static int	is_map_closed(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (map->grid[y][x] == '0' || ft_strchr("NSEW", map->grid[y][x]))
			{
				if (y == 0 || (int)ft_strlen(map->grid[y - 1]) <= x
					|| map->grid[y - 1][x] == ' ')
					return (print_error("Map is not closed", ERROR));
				if (!map->grid[y + 1] || (int)ft_strlen(map->grid[y + 1]) <= x
					|| map->grid[y + 1][x] == ' ')
					return (print_error("Map is not closed", ERROR));
				if (x == 0 || map->grid[y][x - 1] == ' ')
					return (print_error("Map is not closed", ERROR));
				if (map->grid[y][x + 1] == '\0' || map->grid[y][x + 1] == ' ')
					return (print_error("Map is not closed", ERROR));
			}
		}
	}
	return (0);
}

static int	check_map_rules(t_map *map)
{
	int	y;
	int	x;
	int	player_count;

	y = -1;
	player_count = 0;
	while (map->grid[++y])
	{
		x = -1;
		while (map->grid[y][++x])
		{
			if (!is_valid_grid_char(map->grid[y][x]))
				return (print_error("Invalid character in map grid", ERROR));
			if (ft_strchr("NSEW", map->grid[y][x]))
				player_count++;
		}
	}
	if (player_count == 0)
		return (print_error("No player start position found", ERROR));
	if (player_count > 1)
		return (print_error("Multiple player start positions found", ERROR));
	return (0);
}

int	validate_map_grid(t_map *map)
{
	if (!map->grid || !map->grid[0])
		return (print_error("No map grid found", ERROR));
	if (check_map_rules(map) == ERROR)
		return (ERROR);
	if (is_map_closed(map) == ERROR)
		return (ERROR);
	return (0);
}
