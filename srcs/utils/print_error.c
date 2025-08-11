/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raydogmu <raydogmu@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:21:52 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/11 07:45:27 by raydogmu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *message, int error_code)
{
	ft_putstr_fd("Error\ncub3D: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (error_code);
}

void	*print_null(char *message)
{
	ft_putstr_fd("Error\ncub3D: ", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (NULL);
}
