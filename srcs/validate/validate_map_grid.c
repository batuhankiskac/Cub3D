/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:28:06 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/11 14:27:18 by bkiskac          ###   ########.fr       */
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

static void	find_player_start(char **grid, int *x, int *y)
{
	*y = 0;
	while (grid[*y])
	{
		*x = 0;
		while (grid[*y][*x])
		{
			if (ft_strchr("NSEW", grid[*y][*x]))
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

static int	flood_fill(char **grid, int y, int x, int height)
{
	if (y < 0 || y >= height || x < 0 || !grid[y][x] || grid[y][x] == ' ')
		return (print_error("Map is not closed", ERROR));
	if (grid[y][x] == '1' || grid[y][x] == 'F')
		return (0);
	grid[y][x] = 'F';
	if (flood_fill(grid, y + 1, x, height) == ERROR)
		return (ERROR);
	if (flood_fill(grid, y - 1, x, height) == ERROR)
		return (ERROR);
	if (flood_fill(grid, y, x + 1, height) == ERROR)
		return (ERROR);
	if (flood_fill(grid, y, x - 1, height) == ERROR)
		return (ERROR);
	return (0);
}

static int	execute_fill(t_map *map)
{
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		result;

	map_copy = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	if (!map_copy)
		return (print_error("Malloc failed", ERROR));
	player_y = 0;
	while (player_y < map->map_height)
	{
		map_copy[player_y] = ft_strdup(map->grid[player_y]);
		if (!map_copy[player_y++])
		{
			free_all(map_copy);
			return (print_error("Malloc failed", ERROR));
		}
	}
	map_copy[player_y] = NULL;
	find_player_start(map_copy, &player_x, &player_y);
	result = flood_fill(map_copy, player_y, player_x, map->map_height);
	free_all(map_copy);
	return (result);
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
