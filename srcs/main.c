/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:53:40 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/21 11:20:22 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render_next_frame(t_cub3d *cub3d)
{
	draw_background(cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->img.img_ptr, 0, 0);
	raycaster(cub3d);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d	cub3d;

	if (argc != 2)
		return (print_error("Usage: ./cub3d <path_to_map.cub>", ERROR));
	init_data(&cub3d);
	if (parse_file(&cub3d, argv[1]) == ERROR)
	{
		cleanup(&cub3d);
		return (ERROR);
	}
	if (init_mlx(&cub3d) == ERROR)
	{
		cleanup(&cub3d);
		return (ERROR);
	}
	player_init(&cub3d);
	setup_hooks(&cub3d);
	mlx_loop_hook(cub3d.mlx, &render_next_frame, &cub3d);
	mlx_loop(cub3d.mlx);
	return (0);
}
