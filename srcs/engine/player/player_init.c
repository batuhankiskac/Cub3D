/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:33:02 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/12 15:07:30 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_player_dir_ns(t_player *player, char dir_char)
{
	if (dir_char == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (dir_char == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

static void	set_player_dir_we(t_player *player, char dir_char)
{
	if (dir_char == 'W')
	{
		player->dir_x = -1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = -0.66;
	}
	else if (dir_char == 'E')
	{
		player->dir_x = 1;
		player->dir_y = 0;
		player->plane_x = 0;
		player->plane_y = 0.66;
	}
}

void	player_init(t_cub3d *cub3d)
{
	int	y;
	int	x;

	y = -1;
	while (++y < cub3d->map.map_height)
	{
		x = -1;
		while (cub3d->map.grid[y][++x])
		{
			if (ft_strchr("NSEW", cub3d->map.grid[y][x]))
			{
				cub3d->player.pos_x = x + 0.5;
				cub3d->player.pos_y = y + 0.5;
				if (cub3d->map.grid[y][x] == 'N'
					|| cub3d->map.grid[y][x] == 'S')
					set_player_dir_ns(&cub3d->player, cub3d->map.grid[y][x]);
				else
					set_player_dir_we(&cub3d->player, cub3d->map.grid[y][x]);
				cub3d->map.grid[y][x] = '0';
				return ;
			}
		}
	}
}
