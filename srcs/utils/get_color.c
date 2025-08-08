/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:28:59 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/08 18:41:08 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	validate_rgb_parts(char **rgb_parts, int *rgb_int)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (rgb_parts[i][++j])
			if (!ft_isdigit(rgb_parts[i][j]))
				return (print_error("Non-digit color value!", ERROR));
		rgb_int[i] = ft_atoi(rgb_parts[i]);
		if (rgb_int[i] < 0 || rgb_int[i] > 255)
			return (print_error("Color value out of range (0-255)", ERROR));
	}
	return (0);
}

static char	**split_rgb_str(char *rgb_str)
{
	char	**rgb_parts;
	int		count;

	rgb_parts = ft_split(rgb_str, ',');
	if (!rgb_parts)
		return (print_null("Memory allocation failed for RGB parts"));
	count = 0;
	while (rgb_parts[count])
		count++;
	if (count != 3)
	{
		free_all(rgb_parts);
		return (print_null("Invalid color format: Must be R,G,B"));
	}
	return (rgb_parts);
}

int	get_color_from_rgb(char *rgb_str)
{
	char	**rgb_parts;
	int		rgb_int[3];
	int		color;

	rgb_parts = split_rgb_str(rgb_str);
	if (!rgb_parts)
		return (-1);
	if (validate_rgb_parts(rgb_parts, rgb_int) == ERROR)
	{
		free_all(rgb_parts);
		return (-1);
	}
	color = (rgb_int[0] << 16) | (rgb_int[1] << 8) | rgb_int[2];
	free_all(rgb_parts);
	return (color);
}
