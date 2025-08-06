/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:24:35 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/06 15:52:01 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	validate_map(t_map *map)
{
	if (map->map_width <= 0 || map->map_height <= 0)
		return (print_error("Map dimensions are invalid", ERROR));
	if (validate_map_grid(map) == ERROR)
		return (ERROR);
	if (validate_elements(map) == ERROR)
		return (ERROR);
}
