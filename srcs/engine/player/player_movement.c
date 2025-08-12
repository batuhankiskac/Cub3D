/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:09:39 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/12 17:08:32 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_forward_backward(t_cub3d *cub3d, double move_speed, int dir)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub3d->player.pos_x + dir * cub3d->player.dir_x * move_speed;
	new_pos_y = cub3d->player.pos_y + dir * cub3d->player.dir_y * move_speed;
	if (cub3d->map.grid[(int)new_pos_y][(int)cub3d->player.pos_x] != '1')
		cub3d->player.pos_y = new_pos_y;
	if (cub3d->map.grid[(int)cub3d->player.pos_y][(int)new_pos_x] != '1')
		cub3d->player.pos_x = new_pos_x;
}

static void	move_left_right(t_cub3d *cub3d, double move_speed, int dir)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = cub3d->player.pos_x + dir * cub3d->player.plane_x * move_speed;
	new_pos_y = cub3d->player.pos_y + dir * cub3d->player.plane_y * move_speed;
	if (cub3d->map.grid[(int)new_pos_y][(int)cub3d->player.pos_x] != '1')
		cub3d->player.pos_y = new_pos_y;
	if (cub3d->map.grid[(int)cub3d->player.pos_y][(int)new_pos_x] != '1')
		cub3d->player.pos_x = new_pos_x;
}


void	move_player(t_cub3d *cub3d, int keycode)
{
	double	move_speed;

	move_speed = 0.1;
	if (keycode == XK_w)
		move_forward_backward(cub3d, move_speed, -1);
	else if (keycode == XK_s)
		move_forward_backward(cub3d, move_speed, 1);
	if (keycode == XK_a)
		move_left_right(cub3d, move_speed, -1);
	else if (keycode == XK_d)
		move_left_right(cub3d, move_speed, 1);
}
