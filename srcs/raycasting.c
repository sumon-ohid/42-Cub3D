/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:21 by msumon            #+#    #+#             */
/*   Updated: 2024/06/26 10:37:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycast(t_data *data, t_point direction, double delta_x, double delta_y)
{
	t_point	point;

	data->ray_num = 0;
	point.x = data->player->x;
	point.y = data->player->y;
	delta_x = (direction.x - data->player->x);
	delta_y = (direction.y - data->player->y);
	direction.x = (delta_x * cos(-FOV / 2) - delta_y * sin(-FOV / 2))
		+ data->player->x;
	direction.y = (delta_x * sin(-FOV / 2) + delta_y * cos(-FOV / 2))
		+ data->player->y;
	data->ray_angle = -FOV / 2;
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
