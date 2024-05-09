/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:50:45 by msumon            #+#    #+#             */
/*   Updated: 2024/05/09 15:56:09 by msumon           ###   ########.fr       */
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
# define TILE_SIZE 32
# define WIN_H 1080
# define WIN_W 1920
# define IMG_W 32
# define IMG_H 32

// data structures for img
typedef struct s_img
{
	void	*img_ptr;
	int		width;
	int		height;
	char	*img_path;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

// data structures for main data
typedef struct s_data
{
	t_img	floor_img;
	t_img	ceiling_img;
	t_img	no_img;
	t_img	so_img;
	t_img	we_img;
	t_img	ea_img;
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*sprite_texture;
	char	*floor_color;
	char	*ceiling_color;
	char	**map;
	int		map_width;
	int		map_height;
}			t_data;

// main
int			error(char *str);
int			main(int ac, char **av);

// map_validation
int			map_validation(char *map, int i);
int			free_array(char **array);
int			map_line_count(char *map);

// data_init
int			data_init(t_data *data, t_img *img, char *map_path);

// create_textures
int			create_textures(t_data *data);

#endif