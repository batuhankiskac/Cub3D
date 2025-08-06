/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:08:50 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/06 16:04:43 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(t_cub3d *cub3d, char *filename)
{
	// map structının içeriğini dolduran fonksiyon
	// devamı yazılacak...

	// validate map örnek kullanım
	if (validate_map(&cub3d->map) == ERROR)
	{
		free_all(cub3d->map.grid);
		return (ERROR);
	}
	return (0);
}
