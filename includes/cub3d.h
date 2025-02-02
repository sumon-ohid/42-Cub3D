/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:50:45 by msumon            #+#    #+#             */
/*   Updated: 2024/10/18 11:22:39 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// include libraries
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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
# define ROTATE_ANGLE 0.1
# define FOV 1.0471975512
# define DIR_L 100
# define SPEED 200
# define EMPTY '0'
# define WALL '1'
# define IMG_SIZE 1024
# define WIN_H 900
# define WIN_W 1800

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
	bool		gnl_failed;
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
int				is_empty(const char *str);
int				valid_map(t_data *data);
int				map_parser(t_data *data);
int				height_until_map(char **map);
int				map_without_textures(char **map, t_data *data);
char			*remove_space(char *line);
int				valid_chars(t_data *data);
int				has_char(const char *set, char c);
int				load_textures_and_colors(t_data *data, int i);
int				map_without_textures(char **map, t_data *data);
char			*copy_until_newline(char *line);
int				parse_color(char *line, int i);
int				has_player(t_data *data);
int				valid_borders(t_data *data);
int				exact_map_height(char **map);
int				exact_width(char *line);
int				empty_line_check(char *line, int flag);
char			*remove_extra_space(char *input, int i, int j);
int				get_max_width(char **map);
int				space_checker(t_data *data, size_t x, int y);
int				empty_checker(t_data *data, int x, int y);

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

// set_environment
void			create_background(t_data *data);
void			set_camera(t_data *data, int x, int y);

// raycast
void			raycast(t_data *data, t_point direction, double delta_x,
					double delta_y);
void			draw_line(t_data *data, t_point point1, t_point point2,
					int index);
void			add_image_pixel(t_data *data, t_point point, double x_c,
					double y_c);
// cleanup
int				close_game(t_data *data);
void			free_array(char **array);
void			clean_input_structure(t_data *data);
void			clean_data(t_data *data);
int				clean_and_error(t_data *data, char *message);

// lib
int				ft_isspace(char c);
int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c, size_t i, size_t j);

// get_next_line
char			*get_next_line(int fd, t_data *data);

#endif
