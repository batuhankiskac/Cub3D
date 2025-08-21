/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:17:23 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/21 12:31:13 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*init_textures(t_cub3d *cub3d)
{
	int	size;

	size = 64;
	cub3d->east_img = mlx_xpm_file_to_image(cub3d->mlx,
			"textures/east.xpm", &size, &size);
	cub3d->west_img = mlx_xpm_file_to_image(cub3d->mlx,
			"textures/west.xpm", &size, &size);
	cub3d->north_img = mlx_xpm_file_to_image(cub3d->mlx,
			"textures/north.xpm", &size, &size);
	cub3d->south_img = mlx_xpm_file_to_image(cub3d->mlx,
			"textures/south.xpm", &size, &size);
	if (!cub3d->east_img || !cub3d->west_img
			|| !cub3d->north_img || !cub3d->south_img)
		return (print_null("Texture files is wrong"));
	return ((void *)1);
}

int	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (print_error("Failed to initialize mlx", ERROR));
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!cub3d->win)
		return (print_error("Failed to initialize mlx", ERROR));
	cub3d->img.img_ptr = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub3d->img.img_ptr)
		return (print_error("Failed to initialize mlx", ERROR));
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img_ptr,
			&cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
	if (!cub3d->img.addr)
		return (print_error("Failed to initialize mlx", ERROR));
	if (!init_textures(cub3d))
		return (ERROR);
	return (0);
}
