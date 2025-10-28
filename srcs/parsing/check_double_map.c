/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:35:15 by raydogmu          #+#    #+#             */
/*   Updated: 2025/10/28 15:05:10 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_longest_line_length(char **map)
{
	int	final;
	int	i;
	int	len;

	final = 0;
	i = 0;
	if (!map)
		return (0);
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > final)
			final = len;
		i++;
	}
	return (final);
}

static int	get_line_count(char **map)
{
	int	count;

	if (!map)
		return (0);
	count = 0;
	while (map[count])
		count++;
	return (count);
}

static void	fill_line(char *line, int len, int longest_num)
{
	int i;

	if (!line)
		return ;
	i = len;
	while (i < longest_num)
	{
		line[i] = ' ';
		i++;
	}
	line[longest_num] = '\0';
}

static char	**get_required_map(char **map, int longest_num)
{
	char	**result;
	int		i;
	int		len;
	int		lines;

	lines = get_line_count(map);
	result = malloc(sizeof(char *) * (lines + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < lines)
	{
		len = ft_strlen(map[i]);
		result[i] = malloc(sizeof(char) * (longest_num + 1));
		if (!result[i])
		{
			free_all(result);
			return (NULL);
		}
		ft_memmove(result[i], map[i], len);
		fill_line(result[i], len, longest_num);
		i++;
	}
	result[i] = NULL;
	return (result);
}

void	print_map(char **map)
{
	int	i;

	if (!map)
	{
		printf("(null)\n");
		return;
	}
	i = 0;
	while (map[i])
	{
		printf("%s-\n", map[i]);
		i++;
	}
}

int	check_double_map(char **map)
{
	char	**result;

	if (!map)
		return (print_error("No mem!", 1));
	result = get_required_map(map, get_longest_line_length(map));
	if (!result)
		return (print_error("No mem!", 1));
	print_map(result);
	return (0);
}
