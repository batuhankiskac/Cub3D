/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 14:28:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/16 14:32:15 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(t_cub3d *cub3d, char *filename)
{
	t_map	*temp;

	temp = get_filled_t_map(filename);
	if (!temp)
		return (ERROR);
	cub3d->map = *temp;
	free(temp);
	if (validate_map(&cub3d->map) == ERROR)
		return (ERROR);
	return (0);
}
