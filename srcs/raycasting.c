/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:21 by msumon            #+#    #+#             */
/*   Updated: 2024/06/27 19:15:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
