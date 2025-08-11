/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:08:50 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/11 11:25:14 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(t_cub3d *cub3d, char *filename)
{
	t_map	*temp_map;

	temp_map = get_filled_t_map(filename);
	if (!temp_map)
		return (ERROR);
	cub3d->map = *temp_map;
	free(temp_map);
	if (validate_map(&cub3d->map) == ERROR)
	{
		free(cub3d->map.north_texture_path);
		free(cub3d->map.south_texture_path);
		free(cub3d->map.west_texture_path);
		free(cub3d->map.east_texture_path);
		free_all(cub3d->map.grid);
		return (ERROR);
	}
	return (0);
}
