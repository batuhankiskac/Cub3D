/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 07:39:09 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/10 15:13:06 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_t_map(t_map *map)
{
	free(map->north_texture_path);
	free(map->south_texture_path);
	free(map->west_texture_path);
	free(map->east_texture_path);
	free_all(map->grid);
	free(map);
}
