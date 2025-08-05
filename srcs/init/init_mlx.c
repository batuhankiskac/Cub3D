/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:17:23 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/05 18:21:07 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	init_error(void)
{
	ft_putstr_fd("Error: Failed to initialize MLX.\n", STDERR_FILENO);
	return (ERROR);
}

int	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (init_error());
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!cub3d->win)
		return (init_error());
}
