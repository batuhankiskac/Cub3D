/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:05:19 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/12 17:30:20 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(t_cub3d *cub3d, int keycode)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	rot_speed = 0.05;
	angle = 0;
	if (keycode == XK_Left)
		angle = -rot_speed;
	else if (keycode == XK_Right)
		angle = rot_speed;
	if (angle == 0)
		return ;
	old_dir_x = cub3d->player.dir_x;
	old_plane_x = cub3d->player.plane_x;
	cub3d->player.dir_x = cub3d->player.dir_x * cos(angle)
		- cub3d->player.dir_y * sin(angle);
	cub3d->player.dir_y = old_dir_x * sin(angle)
		+ cub3d->player.dir_y * cos(angle);
	cub3d->player.plane_x = cub3d->player.plane_x * cos(angle)
		- cub3d->player.plane_y * sin(angle);
	cub3d->player.plane_y = old_plane_x * sin(angle)
		+ cub3d->player.plane_y * cos(angle);
}
