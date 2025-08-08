/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:21:52 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/08 18:43:18 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	print_error(char *message, int error_code)
{
	ft_putstr_fd("Error\n cub3d:", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (error_code);
}

void	*print_null(char *message)
{
	ft_putstr_fd("Error\n cub3d:", STDERR_FILENO);
	ft_putendl_fd(message, STDERR_FILENO);
	return (NULL);
}
