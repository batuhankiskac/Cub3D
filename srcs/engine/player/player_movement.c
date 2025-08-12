/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:09:39 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/12 15:16:11 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
