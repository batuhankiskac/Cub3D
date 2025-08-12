/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:34:32 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/12 18:08:39 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_press_handler(int keycode, t_cub3d *cub3d)
{
	if (keycode == XK_Escape)
		cleanup_and_exit(cub3d);
	else if (keycode == XK_w || keycode == XK_s || keycode == XK_a
			|| keycode == XK_d)
		move_player(cub3d, keycode);
	else if (keycode == XK_Left || keycode == XK_Right)
		rotate_player(cub3d, keycode);
	// Test için raycast hazır olduktan sonra silerim
	printf("Player Pos: (X=%.2f, Y=%.2f) | Player Dir: (X=%.2f, Y=%.2f)\n",
		cub3d->player.pos_x, cub3d->player.pos_y,
		cub3d->player.dir_x, cub3d->player.dir_y);
	return (0);
}

void	setup_hooks(t_cub3d *cub3d)
{
	mlx_hook(cub3d->win, KeyPress, KeyPressMask, &key_press_handler, (void *)cub3d);
	mlx_hook(cub3d->win, DestroyNotify, ButtonPressMask, &cleanup_and_exit,
			(void *)cub3d);
}
