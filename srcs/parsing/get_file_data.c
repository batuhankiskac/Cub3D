/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 06:35:11 by raydogmu          #+#    #+#             */
/*   Updated: 2025/08/04 13:56:51 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	is_extension_true(char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (size >= 5)
	{
		if (filename[size - 1] == 'b'
			&& filename[size - 2] == 'u'
			&& filename[size - 3] == 'c'
			&& filename[size - 4] == '.'
			&& !(filename[size - 5] >= 9 && filename[size - 5] <= 13)
			&& !(filename[size - 5] == ' '))
			return (1);
	}
	ft_putstr_fd("Error\ncub3D: map file is wrong.\n", 2);
	return (0);
}

static int	open_file(char *filename)
{
	int		fd;
	char	buffer;
	int		readed;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\ncub3D");
		return (-1);
	}
	readed = read(fd, &buffer, 1);
	close(fd);
	if (readed != 1)
	{
		ft_putstr_fd("Error\ncub3D: no map found.\n", 2);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\ncub3D");
		return (-1);
	}
	return (fd);
}

static char	**get_data(char *filename)
{
	int		fd;
	char	**data;
	char	*line;

	data = NULL;
	line = NULL;
	fd = open_file(filename);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data = get_swords(data, line);
		free(line);
		if (!data)
			break ;
	}
	close(fd);
	return (data);
}

char	**get_file_data(char *filename)
{
	int		fd;
	char	**data;

	if (!filename)
		return (NULL);
	if (!is_extension_true(filename))
		return (NULL);
	fd = open_file(filename);
	if (fd == -1)
		return (NULL);
	data = get_data(filename);
	if (!data)
		return (NULL);
	return (data);
}
