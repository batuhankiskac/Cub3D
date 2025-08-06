/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:23:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/06 14:11:36 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/time.h>
# include <math.h>
# include <errno.h>

# define ERROR -2
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	**grid;
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	int		floor_color;
	int		ceiling_color;
	int		map_width;
	int		map_height;
}			t_map;

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
}			t_cub3d;

/*
** Init
*/
int		init_data(t_cub3d *cub3d);
int		init_mlx(t_cub3d *cub3d);

/*
** Parser
*/
int		parse_file(t_cub3d *cub3d, char *filename);
char	**get_swords(char **words, char *word);
char	**get_file_data(char *filename);

/*
** Utils
*/
void	free_all(char **arr);

#endif
