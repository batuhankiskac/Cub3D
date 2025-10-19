/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 19:10:04 by bkiskac           #+#    #+#             */
/*   Updated: 2025/10/19 18:35:05 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perform_dda(t_map *map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = FACE_EW;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = FACE_NS;
		}
		if (ray->map_x < 0 || ray->map_x >= map->map_width ||
			ray->map_y < 0 || ray->map_y >= map->map_height)
		{
			ray->hit = 1;
			break;
		}
		if (map->grid[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}
