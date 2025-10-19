/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:05:09 by bkiskac           #+#    #+#             */
/*   Updated: 2025/10/19 15:55:55 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_wall_height(t_ray *ray, t_player *player)
{
	double	euclidean_dist;

	if (ray->side == FACE_EW)
		euclidean_dist = ray->side_dist_x - ray->delta_dist_x;
	else
		euclidean_dist = ray->side_dist_y - ray->delta_dist_y;
	if (ray->perp_wall_dist <= 0)
		ray->perp_wall_dist = 1e30;
	ray->perp_wall_dist = (euclidean_dist * ray->ray_dir_x) * player->dir_x
		+ (euclidean_dist * ray->ray_dir_y) * player->dir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = (WIN_HEIGHT / 2) - (ray->line_height / 2);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (WIN_HEIGHT / 2) + (ray->line_height / 2);
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static void	draw_slice(t_cub3d *cub3d, t_ray *ray, int x)
{
	t_img	*texture;
	int		y;
	int		color;

	texture = get_wall_texture(cub3d, ray);
	calculate_texture_x(&cub3d->player, ray, texture);
	ray->tex_step = (double)texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2)
		* ray->tex_step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		ray->tex_y = (int)ray->tex_pos;
		ray->tex_pos += ray->tex_step;
		color = get_texture_color(texture, ray->tex_x, ray->tex_y);
		put_pixel_to_image(&cub3d->img, x, y, color);
	}
}

void	raycaster(t_cub3d *cub3d)
{
	t_ray	ray;
	int		x;

	x = -1;
	while (++x < WIN_WIDTH)
	{
		ray_init(&cub3d->player, &ray, x);
		perform_dda(&cub3d->map, &ray);
		calculate_wall_height(&ray, &cub3d->player);
		draw_slice(cub3d, &ray, x);
	}
}
