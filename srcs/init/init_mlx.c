/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:17:23 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/23 13:35:39 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	init_single_texture(t_cub3d *cub3d, t_img *texture, char *path)
{
	texture->img_ptr = mlx_xpm_file_to_image(cub3d->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img_ptr)
		return (print_error("Failed to initialize texture image", ERROR));
	texture->addr = mlx_get_data_addr(texture->img_ptr, &texture->bpp,
			&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (print_error("Failed to get texture data address", ERROR));
	return (0);
}

static int	init_textures(t_cub3d *cub3d)
{
	if (init_single_texture(cub3d, &cub3d->ea_img,
		cub3d->map.east_texture_path) == ERROR)
		return (ERROR);
	if (init_single_texture(cub3d, &cub3d->no_img,
		cub3d->map.north_texture_path) == ERROR)
		return (ERROR);
	if (init_single_texture(cub3d, &cub3d->so_img,
		cub3d->map.south_texture_path) == ERROR)
		return (ERROR);
	if (init_single_texture(cub3d, &cub3d->we_img,
		cub3d->map.west_texture_path) == ERROR)
		return (ERROR);
	return (0);
}

int	init_mlx(t_cub3d *cub3d)
{
	cub3d->mlx = mlx_init();
	if (!cub3d->mlx)
		return (print_error("Failed to initialize mlx", ERROR));
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!cub3d->win)
		return (print_error("Failed to initialize window", ERROR));
	cub3d->img.img_ptr = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cub3d->img.img_ptr)
		return (print_error("Failed to initialize main image", ERROR));
	cub3d->img.addr = mlx_get_data_addr(cub3d->img.img_ptr,
			&cub3d->img.bpp, &cub3d->img.line_len, &cub3d->img.endian);
	if (!cub3d->img.addr)
		return (print_error("Failed to get main image data address", ERROR));
	if (init_textures(cub3d) == ERROR)
		return (ERROR);
	return (0);
}

