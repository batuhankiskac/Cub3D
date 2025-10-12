/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 06:58:53 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/26 07:19:11 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_first_line_of_map(char **data, int i)
{
	if (!data || i < 0)
		return (0);
	if (ft_strlen(data[i]) <= 1)
		return (0);
	if (ft_strnstr(data[i], "NO", ft_strlen(data[i]))
		|| ft_strnstr(data[i], "EA", ft_strlen(data[i]))
		|| ft_strnstr(data[i], "WE", ft_strlen(data[i]))
		|| ft_strnstr(data[i], "SO", ft_strlen(data[i]))
		|| ft_strnstr(data[i], "F", ft_strlen(data[i]))
		|| ft_strnstr(data[i], "C", ft_strlen(data[i])))
		return (0);
	return (1);
}

int	check_textures(char **data)
{
	int			i;
	int			num;
	const char	*values[] = {"NO", "EA", "WE", "SO", "F", "C", NULL};
	int			flag;

	i = 0;
	while (values[i])
	{
		num = 0;
		flag = 0;
		while (data[num])
		{
			if (ft_strncmp(data[num], values[i], ft_strlen(values[i])) == 0)
				flag++;
			num++;
		}
		if (flag >= 2)
			return (1);
		i++;
	}
	return (0);
}
