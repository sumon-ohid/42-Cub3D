/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:50:45 by msumon            #+#    #+#             */
/*   Updated: 2024/05/11 10:15:56 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// include libraries
# include "../srcs/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// macros
# define TILE_SIZE 64
# define IMAGE_SIZE 1024
# define WIN_H 800
# define WIN_W 1400
# define IMG_W 64
# define IMG_H 64

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53
# define CROSS_KEY 17

# define PI 3.14159265359
# define ROTATE_SPEED 0.17
# define MOVE_SPEED 0.1
# define FOV 1.0472
# define DIR_L 100
# define SPEED 200
# define EMPTY '0'
# define WALL '1'

// data structures for img
typedef struct s_img
{
	void		*img_ptr;
	int 		*pixels;
	int			width;
	int			height;
	char		*img_path;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

// data structures for player
typedef struct s_player
{
	char		player;
	double		x;
	double		y;
}				t_player;

// data structures for point
typedef struct s_point
{
	double		x;
	double		y;
	int			color;
}				t_point;

// data structures for main data
typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	char		*sprite_texture;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	int			map_width;
	int			map_height;
	int			ray_num;
	int 		ray_angle;
	double		ty_step;
	t_player	player;
	t_point		dir;
	t_point		plane;
	t_point 	plane2;
	t_img		*img;
	t_img		*no_img;
	t_img		*so_img;
	t_img		*we_img;
	t_img		*ea_img;
}				t_data;

// main
int				error(char *str);
int				main(int ac, char **av);

// map_validation
// int				map_validation(char *map, int i);
// int				free_array(char **array);
// int				map_line_count(char *map);

int				is_valid_map(t_data *data);

// data_init
int				data_init(t_data *data, char *map_path);

// create_textures
int				create_textures(t_data *data);

// move_player
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			turn_right(t_data *data);
void			turn_left(t_data *data);

// ft_mlx
void			create_new_image(t_data *data, int width, int height);
void			create_background(t_data *data);
void			set_camera(t_data *data, int x, int y);

// raycast
void			raycast(t_data *data, t_point dir, double length);

#endif