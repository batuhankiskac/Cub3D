/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 06:58:53 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/25 07:20:17 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_line_elements(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (!(s[i] == ' ' || s[i] == '1' || s[i] == '0' || s[i] == 'N'
			|| s[i] == 'W' || s[i] == 'E' || s[i] == 'S' || s[i] == '\n'))
			return (0);
		i++;
	}
	return (1);
}

int	is_first_line_of_map(char **data, int i)
{
	if (!data || i < 0)
		return (0);
	if (ft_strlen(data[i]) <= 1)
		return (0);
	while (data[i])
	{
		if (!check_line_elements(data[i]))
			return (0);
		i++;
	}
	return (1);
}
