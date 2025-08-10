/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:14:35 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/07 07:45:28 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_cub3d *cub3d)
{
	cub3d->mlx = NULL;
	cub3d->win = NULL;
	cub3d->img.img_ptr = NULL;
	cub3d->map.grid = NULL;
	cub3d->map.north_texture_path = NULL;
	cub3d->map.south_texture_path = NULL;
	cub3d->map.west_texture_path = NULL;
	cub3d->map.east_texture_path = NULL;
	cub3d->map.floor_color = -1;
	cub3d->map.ceiling_color = -1;
	return (0);
}

t_map	*get_initialized_map(void)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->north_texture_path = NULL;
	map->south_texture_path = NULL;
	map->west_texture_path = NULL;
	map->east_texture_path = NULL;
	map->grid = NULL;
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->map_width = -1;
	map->map_height = -1;
	return (map);
}
