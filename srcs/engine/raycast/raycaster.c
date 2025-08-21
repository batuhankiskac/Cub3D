/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 10:05:09 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/21 11:45:42 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void calculate_wall_height(t_ray *ray, t_player *player)
{
	if (ray->side == FACE_EW)
		ray->perp_wall_dist = (ray->map_x - player->pos_x
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->pos_y
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
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
	int	y;
	int	color;

	if (ray->side == FACE_NS)
		color = 0x00FF0000;
	else
		color = 0x0000FF00;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		put_pixel_to_image(&cub3d->img, x, y, color);
		y++;
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
