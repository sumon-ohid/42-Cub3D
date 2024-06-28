/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:21 by msumon            #+#    #+#             */
/*   Updated: 2024/06/28 10:31:58 by msumon           ###   ########.fr       */
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

void	initialize_vars(t_data *data, t_point *direction, double *delta_x,
		double *delta_y)
{
	data->ray_num = 0;
	*delta_x = (direction->x - data->player->x);
	*delta_y = (direction->y - data->player->y);
	direction->x = (*delta_x * cos(-FOV / 2) - *delta_y * sin(-FOV / 2))
		+ data->player->x;
	direction->y = (*delta_x * sin(-FOV / 2) + *delta_y * cos(-FOV / 2))
		+ data->player->y;
	data->ray_angle = -FOV / 2;
}

void	raycast(t_data *data, t_point direction, double delta_x, double delta_y)
{
	t_point	point;

	point.x = data->player->x;
	point.y = data->player->y;
	initialize_vars(data, &direction, &delta_x, &delta_y);
	while (data->ray_num < WIN_W)
	{
		draw_line(data, point, direction, 0);
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
