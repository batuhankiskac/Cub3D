/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:42:23 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/12 17:49:05 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map_members(t_map *map)
{
	if (map->grid)
		free_all(map->grid);
	if (map->north_texture_path)
		free(map->north_texture_path);
	if (map->south_texture_path)
		free(map->south_texture_path);
	if (map->west_texture_path)
		free(map->west_texture_path);
	if (map->east_texture_path)
		free(map->east_texture_path);
}

int	cleanup(t_cub3d *cub3d)
{
	if (!cub3d)
		return (1);
	free_map_members(&cub3d->map);
	if (cub3d->img.img_ptr)
		mlx_destroy_image(cub3d->mlx, cub3d->img.img_ptr);
	if (cub3d->win)
		mlx_destroy_window(cub3d->mlx, cub3d->win);
	if (cub3d->mlx)
	{
		mlx_destroy_display(cub3d->mlx);
		free(cub3d->mlx);
	}
	return (0);
}

int	cleanup_and_exit(t_cub3d *cub3d)
{
	cleanup(cub3d);
	exit(0);
	return (0);
}
