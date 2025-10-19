/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:19:34 by raydogmu          #+#    #+#             */
/*   Updated: 2025/10/19 11:36:52 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**edit_blanks(char *s)
{
	char	**elements;
	char	*line;
	int		i;

	if (!s)
		return (NULL);
	elements = ft_split(s, ',');
	i = 0;
	if (!elements)
		return (NULL);
	while (elements[i])
	{
		line = ft_strtrim(elements[i], " ");
		if (!line)
		{
			free_all(elements);
			return (NULL);
		}
		free(elements[i]);
		elements[i] = line;
		i++;
	}
	return (elements);
}

static char	*merge_all_elements(char **elements, char *s)
{
	int	i;
	int	y;
	int	z;

	i = 0;
	z = 0;
	while (elements[i])
	{
		y = 0;
		while (elements[i][y])
		{
			s[z] = elements[i][y];
			y++;
			z++;
		}
		if (elements[i + 1])
			s[z++] = ',';
		i++;
	}
	s[z] = '\0';
	return (s);
}

char	*get_rgb_string(const char *s)
{
	char	*mem;
	int		i;
	char	**elements;
	char	*result;

	i = 1;
	mem = malloc(ft_strlen(s) + 1);
	if (!mem)
		return (NULL);
	while (s[i] != '\n')
	{
		mem[i - 1] = s[i];
		i++;
	}
	mem[i - 1] = '\0';
	elements = edit_blanks(mem);
	if (!elements)
	{
		free(mem);
		return (NULL);
	}
	result = merge_all_elements(elements, mem);
	free_all(elements);
	return (result);
}
