/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiskac <bkiskac@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 21:23:51 by bkiskac           #+#    #+#             */
/*   Updated: 2025/08/12 18:02:12 by bkiskac          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
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

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_player;

typedef struct s_ray
{
	// raycast kısmı için struct
}			t_ray;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map;
	t_player	player;
}			t_cub3d;

/*
** Init
*/
int		init_data(t_cub3d *cub3d);
int		init_mlx(t_cub3d *cub3d);
t_map	*get_initialized_map(void);

/*
** Delete
*/

void	free_t_map(t_map *map);

/*
** Validate
*/
int		validate_map_grid(t_map *map);
int		validate_elements(t_map *map);
int		validate_map(t_map *map);

/*
** Parser
*/
char	**get_swords(char **words, char *word);
char	**get_file_data(char *filename);
t_map	*get_filled_t_map(char *filename);
void	set_rgb_and_heights(t_map *map, char **data);

/*
** Engine
*/
void	player_init(t_cub3d *cub3d);
void	move_player(t_cub3d *cub3d, int keycode);
void	rotate_player(t_cub3d *cub3d, int keycode);

/*
** Utils
*/
int		print_error(char *message, int error_code);
int		get_color_from_rgb(char *rgb_str);
int		cleanup(t_cub3d *cub3d);
int		cleanup_and_exit(t_cub3d *cub3d);
void	*print_null(char *message);
void	free_all(char **arr);

#endif
