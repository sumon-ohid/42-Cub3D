/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:50:45 by msumon            #+#    #+#             */
/*   Updated: 2024/06/19 18:27:13 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// include libraries
# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// keycodes mac
// # define A_KEY 0
// # define S_KEY 1
// # define D_KEY 2
// # define W_KEY 13
// # define LEFT_ARROW 123
// # define RIGHT_ARROW 124
// # define ESC 53
// # define CROSS_KEY 17

// keycodes linux
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define W_KEY 119
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307
# define CROSS_KEY 33

// constants
# define ROTATE_ANGLE 0.2
# define FOV 1.0471975512
# define DIR_L 100
# define SPEED 200
# define EMPTY '0'
# define WALL '1'
# define IMG_SIZE 1024
# define WIN_H 900
# define WIN_W 1200

// data structures for img
typedef struct s_img
{
	void		*img_ptr;
	int			*pixels;
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
}				t_point;

// data structures for main data
typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	char		**map;
	char		*map_path;
	int			map_width;
	int			map_height;
	int			ray_num;
	int			ray_angle;
	double		coordinate_y;
	t_player	*player;
	t_point		dir;
	t_point		plane;
	t_point		plane2;
	t_img		*img;
	t_img		*no_img;
	t_img		*so_img;
	t_img		*we_img;
	t_img		*ea_img;
}				t_data;

// main
int				error(char *str);
int				main(int ac, char **av);

// map
int				valid_map(t_data *data);
int				map_parser(t_data *data);
int				map_without_textures(char **map, t_data *data);
char			*remove_space(char *line);
int				valid_chars(t_data *data);
int				has_char(const char *set, char c);
int				load_textures_and_colors(t_data *data);
int				map_without_textures(char **map, t_data *data);
char			*copy_until_newline(char *line);
int				parse_color(char *line, int i);
int				has_player(t_data *data);
int				valid_borders(t_data *data);

// data_init
int				data_init(t_data *data, char *map_path);
int				allocate_textures(t_data *data);
int				map_init(t_data *data, char *map_path, int len);

// create_textures
int				create_textures(t_data *data);

// move_player
void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_left(t_data *data);
void			move_right(t_data *data);
void			turn_right(t_data *data);
void			turn_left(t_data *data);
void			update_x_positions(t_data *data, double delta_x);
void			update_y_positions(t_data *data, double delta_y);

// ft_mlx
void			create_new_image(t_data *data, int width, int height);
void			create_background(t_data *data);
void			set_camera(t_data *data, int x, int y);

// raycast
void			raycast(t_data *data, t_point direction, double delta_x,
					double delta_y);
// cleanup
int				close_game(t_data *data);
void			free_array(char **array);
void			clean_input_structure(t_data *data);
void			clean_data(t_data *data);
int				clean_and_error(t_data *data, char *message);

// extra
void			print_map(t_data *data);
void			cub_minimap(t_data *data);

#endif
