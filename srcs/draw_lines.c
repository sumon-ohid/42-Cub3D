/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:36:40 by msumon            #+#    #+#             */
/*   Updated: 2024/06/26 10:45:37 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	add_image_pixel(t_data *data, t_point point, double x_c,
		double y_c)
{
	double	t_x;
	double	t_y;
	int		index;

	t_x = (int)(point.x) % IMG_SIZE;
	t_y = (int)(point.y) % IMG_SIZE;
	index = WIN_H / 2 - x_c - 1;
	while (++index < WIN_H / 2 + x_c && index < WIN_H)
	{
		if ((int)t_x == 0)
			data->img->pixels[WIN_W * index + data->ray_num]
				= data->ea_img->pixels[(int)y_c * IMG_SIZE + (int)t_y];
		else if ((int)t_y == 0)
			data->img->pixels[WIN_W * index
				+ data->ray_num] = data->so_img->pixels[(int)y_c * IMG_SIZE
				+ IMG_SIZE - 1 - (int)t_x];
		else if ((int)t_x == IMG_SIZE - 1)
			data->img->pixels[WIN_W * index + data->ray_num]
				= data->we_img->pixels[(int)y_c * IMG_SIZE + IMG_SIZE
				- 1 - (int)t_y];
		else if ((int)t_y == IMG_SIZE - 1)
			data->img->pixels[WIN_W * index + data->ray_num]
				= data->no_img->pixels[(int)y_c * IMG_SIZE + (int)t_x];
		y_c += data->coordinate_y;
	}
}

void	draw_texture(t_data *data, double distance, t_point point)
{
	int		x_coord;
	double	texture_y_offset;
	double	y_coord;

	x_coord = (int)(IMG_SIZE * WIN_H / 2 / distance);
	texture_y_offset = 0;
	data->coordinate_y = 1024.0 / (double)(2 * x_coord);
	if (x_coord > WIN_H / 2)
	{
		texture_y_offset = (x_coord - WIN_H / 2);
		x_coord = WIN_H / 2;
	}
	y_coord = texture_y_offset * data->coordinate_y;
	add_image_pixel(data, point, x_coord, y_coord);
}

void	draw_if_empty(t_data *data, t_point point1, double dx)
{
	if (data->map[(int)point1.y / IMG_SIZE][(int)point1.x / IMG_SIZE] == EMPTY)
		point1.x -= dx;
	draw_texture(data, sqrt(pow(data->player->y - point1.y, 2)
			+ pow(data->player->x - point1.x, 2))
		* cos(fabs((double)(data->ray_angle))), point1);
}

void	deltas_and_points(t_point *point1, t_point *point2, double *delta_x,
		double *delta_y)
{
	double	max_value;

	*delta_x = point2->x - point1->x;
	*delta_y = point2->y - point1->y;
	max_value = fmax(fabs(*delta_x), fabs(*delta_y));
	*delta_y /= max_value;
	*delta_x /= max_value;
	point2->x += *delta_x;
	point2->y += *delta_y;
}

void	draw_line(t_data *data, t_point point1, t_point point2, int index)
{
	double	delta_x;
	double	delta_y;
	int		line_width;

	deltas_and_points(&point1, &point2, &delta_x, &delta_y);
	while (1)
	{
		index = (int)point1.y / IMG_SIZE;
		if (index >= 0 && index < data->map_height)
		{
			line_width = ft_strlen(data->map[index]);
			if (IMG_SIZE * line_width > point1.x && IMG_SIZE
				* data->map_height > point1.y && data->map[(int)point1.y
					/ IMG_SIZE][(int)point1.x / IMG_SIZE] != EMPTY)
			{
				draw_if_empty(data, point1, delta_x);
				break ;
			}
		}
		else
			break ;
		point1.x += delta_x;
		point1.y += delta_y;
	}
}
