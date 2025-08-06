/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:08:50 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/06 14:10:30 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(t_cub3d *cub3d, char *filename)
{
	cub3d->map.grid = get_file_data(filename);
	if (!cub3d->map.grid)
	{
		ft_putstr_fd("Error: Could not read file.\n", STDERR_FILENO);
		return (ERROR);
	}
	// map structının içeriğini dolduran fonksiyon
	// devamı yazılacak...
	return (0);
}
