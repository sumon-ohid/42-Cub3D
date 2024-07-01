/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:36:40 by msumon            #+#    #+#             */
/*   Updated: 2024/07/01 13:16:56 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// point is the intersection point of the ray with the wall
// dx is the distance between the player and the intersection point
// distance is the distance between the player and the intersection point
// pythagoras theorem is used to calculate the distance
// sqrt((player.y - point.y)^2 + (player.x - point.x)^2) * cos(ray_angle)
void	draw_texture_if_empty(t_data *data, t_point point, double dx)
{
	double	distance;
	int		x_coord;
	double	texture_y_offset;
	double	y_coord;

	if (data->map[(int)point.y / IMG_SIZE][(int)point.x / IMG_SIZE] == EMPTY)
		point.x -= dx;
	distance = sqrt(pow(data->player->y - point.y, 2) + pow(data->player->x
				- point.x, 2)) * cos(fabs((double)(data->ray_angle)));
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

// point1 and point2 are the start and end points of the line
// delta_x and delta_y are the differences between the x and y coordinates
// max_value is the maximum value between the differences
// delta_x and delta_y are normalized
// point2.x and point2.y are updated by adding delta_x and delta_y
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

	line_width = data->map_width;
	deltas_and_points(&point1, &point2, &delta_x, &delta_y);
	while (1)
	{
		index = (int)point1.y / IMG_SIZE;
		if (index >= 0 && index < data->map_height)
		{
			if (IMG_SIZE * line_width > point1.x && IMG_SIZE
				* data->map_height > point1.y && data->map[(int)point1.y
					/ IMG_SIZE][(int)point1.x / IMG_SIZE] != EMPTY)
			{
				draw_texture_if_empty(data, point1, delta_x);
				break ;
			}
		}
		else
			break ;
		point1.x += delta_x;
		point1.y += delta_y;
	}
}
