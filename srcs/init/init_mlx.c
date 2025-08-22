/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:17:23 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/22 13:07:54 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_textures(t_cub3d *cub3d, int size)
{
	cub3d->ea_img.img_ptr = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map.east_texture_path, &size, &size);
	if (!cub3d->ea_img.img_ptr)
		return (print_error("Failed to initialize EAST IMG PTR", ERROR));
	cub3d->ea_img.addr = mlx_get_data_addr(cub3d->ea_img.img_ptr,
		&cub3d->ea_img.bpp, &cub3d->ea_img.line_len, &cub3d->ea_img.endian);
	cub3d->no_img.img_ptr = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map.north_texture_path, &size, &size);
	if (!cub3d->no_img.img_ptr)
		return (print_error("Failed to initialize NORTH IMG PTR", ERROR));
	cub3d->no_img.addr = mlx_get_data_addr(cub3d->no_img.img_ptr,
		&cub3d->no_img.bpp, &cub3d->no_img.line_len, &cub3d->no_img.endian);
	cub3d->so_img.img_ptr = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map.south_texture_path, &size, &size);
	if (!cub3d->so_img.img_ptr)
		return (print_error("Failed to initialize SOUTH IMG PTR", ERROR));
	cub3d->so_img.addr = mlx_get_data_addr(cub3d->so_img.img_ptr,
		&cub3d->so_img.bpp, &cub3d->so_img.line_len, &cub3d->so_img.endian);
	cub3d->we_img.img_ptr = mlx_xpm_file_to_image(cub3d->mlx,
			cub3d->map.west_texture_path, &size, &size);
	if (!cub3d->we_img.img_ptr)
		return (print_error("Failed to initialize WEST IMG PTR", ERROR));
	cub3d->we_img.addr = mlx_get_data_addr(cub3d->we_img.img_ptr,
		&cub3d->we_img.bpp, &cub3d->we_img.line_len, &cub3d->we_img.endian);
	return (0);
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
	if (init_textures(cub3d, 64) == ERROR)
		return (ERROR);
	return (0);
}
