/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:49:34 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/23 14:53:18 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img	*get_wall_texture(t_cub3d *cub3d, t_ray *ray)
{
	if (ray->side == FACE_NS)
	{
		if (ray->ray_dir_y > 0)
			return (&cub3d->so_img);
		else
			return (&cub3d->no_img);
	}
	else
	{
		if (ray->ray_dir_x > 0)
			return (&cub3d->ea_img);
		else
			return (&cub3d->we_img);
	}
}

void	calculate_texture_x(t_player *player, t_ray *ray, t_img *texture)
{
	if (ray->side == FACE_EW)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)texture->width);
	if ((ray->side == FACE_EW && ray->ray_dir_x < 0)
		|| (ray->side == FACE_NS && ray->ray_dir_y > 0))
		ray->tex_x = texture->width - ray->tex_x - 1;
}

int	get_texture_color(t_img *texture, int x, int y)
{
	char	*dst;

	if (x < 0 || x >= texture->width || y < 0 || y >= texture->height)
		return (0x000000);
	dst = texture->addr + (y * texture->line_len + x * (texture->bpp / 8));
	return (*(unsigned int *)dst);
}
