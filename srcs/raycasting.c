/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:21 by msumon            #+#    #+#             */
/*   Updated: 2024/06/17 15:31:12 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <math.h>

void	add_image_pixel(t_data *data, t_point point, int x_coord,
		double y_coord)
{
	double	texture_x;
	double	texture_y;
	int		index;

	texture_x = (int)(point.x) % IMAGE_SIZE;
	texture_y = (int)(point.y) % IMAGE_SIZE;
	index = WIN_H / 2 - x_coord - 1;
	while (++index < WIN_H / 2 + x_coord && index < WIN_H)
	{
		if ((int)texture_x == 0)
			data->img->pixels[WIN_W * index
				+ data->ray_num] = data->ea_img->pixels[(int)y_coord
				* IMAGE_SIZE + (int)texture_y];
		else if ((int)texture_y == 0)
			data->img->pixels[WIN_W * index
				+ data->ray_num] = data->so_img->pixels[(int)y_coord
				* IMAGE_SIZE + IMAGE_SIZE - 1 - (int)texture_x];
		else if ((int)texture_x == IMAGE_SIZE - 1)
			data->img->pixels[WIN_W * index
				+ data->ray_num] = data->we_img->pixels[(int)y_coord
				* IMAGE_SIZE + IMAGE_SIZE - 1 - (int)texture_y];
		else if ((int)texture_y == IMAGE_SIZE - 1)
			data->img->pixels[WIN_W * index
				+ data->ray_num] = data->no_img->pixels[(int)y_coord
				* IMAGE_SIZE + (int)texture_x];
		y_coord += data->coordinate_y;
	}
}

void	draw_texture(t_data *data, double distance, t_point point)
{
	int		x_coord;
	double	texture_y_offset;
	double	y_coord;

	x_coord = (int)(IMAGE_SIZE * WIN_H / 2 / distance);
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
	if (data->map[(int)point1.y / IMAGE_SIZE][(int)point1.x
		/ IMAGE_SIZE] == EMPTY)
		point1.x -= dx;
	draw_texture(data, sqrt(pow(data->player->y - point1.y, 2)
			+ pow(data->player->x - point1.x, 2)) * cos(fabs((double)(data->ray_angle))),
		point1);
}

// fmax returns the greater of two values
// fabs returns the absolute value of a floating point number
void	draw_line(t_data *data, t_point point1, t_point point2)
{
	double	delta_x;
	double	delta_y;
	double	max_value;
	int		line_width;

	delta_x = point2.x - point1.x;
	delta_y = point2.y - point1.y;
	max_value = fmax(fabs(delta_x), fabs(delta_y));
	delta_y /= max_value;
	delta_x /= max_value;
	point2.x += delta_x;
	point2.y += delta_y;
	while (1)
	{
		line_width = ft_strlen(data->map[(int)point1.y / IMAGE_SIZE]);
		if (IMAGE_SIZE * line_width > point1.x && IMAGE_SIZE
			* data->map_height > point1.y && data->map[(int)point1.y
			/ IMAGE_SIZE][(int)point1.x / IMAGE_SIZE] != EMPTY)
		{
			draw_if_empty(data, point1, delta_x);
			break ;
		}
		point1.x += delta_x;
		point1.y += delta_y;
	}
}

void	raycast(t_data *data, t_point direction)
{
	t_point	point;
	double	delta_x;
	double	delta_y;

	data->ray_num = 0;
	// Set the starting point of the ray
	point.x = data->player->x;
	point.y = data->player->y;
	// change in coordinates for each step
	delta_x = (direction.x - data->player->x);
	delta_y = (direction.y - data->player->y);
	// Rotation matrix
	//_x = x * cos(angle) - y * sin(angle)
	//_y = x * sin(angle) + y * cos(angle)
	direction.x = (delta_x * cos(-FOV / 2) - delta_y * sin(-FOV / 2))
		+ data->player->x;
	direction.y = (delta_x * sin(-FOV / 2) + delta_y * cos(-FOV / 2))
		+ data->player->y;
	data->ray_angle = -FOV / 2;
	while (data->ray_num < WIN_W)
	{
		draw_line(data, point, direction);
		delta_x = (direction.x - data->player->x);
		delta_y = (direction.y - data->player->y);
		direction.x = (delta_x * cos(FOV / WIN_W) - delta_y * sin(FOV / WIN_W))
			+ data->player->x;
		direction.y = (delta_x * sin(FOV / WIN_W) + delta_y * cos(FOV / WIN_W))
			+ data->player->y;
		data->ray_angle += FOV / WIN_W;
		data->ray_num++;
	}
}
