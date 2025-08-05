/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:14:35 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/05 18:16:06 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
