/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:08:45 by msumon            #+#    #+#             */
/*   Updated: 2024/06/11 14:40:52 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_x_positions(t_data *data, double delta_x)
{
	data->player.x += SPEED * delta_x;
	data->dir.x += SPEED * delta_x;
	data->plane.x += SPEED * delta_x;
	data->plane2.x += SPEED * delta_x;
}

void	update_y_positions(t_data *data, double delta_y)
{
	data->player.y += SPEED * delta_y;
	data->dir.y += SPEED * delta_y;
	data->plane.y += SPEED * delta_y;
	data->plane2.y += SPEED * delta_y;
}

void	move_forward(t_data *data)
{
	const double	delta_x = (data->dir.x - data->player.x) / DIR_L;
	const double	delta_y = (data->dir.y - data->player.y) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x + SPEED
			* delta_x) / IMAGE_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}

void	move_backward(t_data *data)
{
	const double	delta_x = -(data->dir.x - data->player.x) / DIR_L;
	const double	delta_y = -(data->dir.y - data->player.y) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x + SPEED
			* delta_x) / IMAGE_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}

void	move_left(t_data *data)
{
	const double	delta_x = (data->dir.y - data->player.y) / DIR_L;
	const double	delta_y = -(data->dir.x - data->player.x) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x + SPEED
			* delta_x) / IMAGE_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}

void	move_right(t_data *data)
{
	const double	delta_x = -(data->dir.y - data->player.y) / DIR_L;
	const double	delta_y = (data->dir.x - data->player.x) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x + SPEED
			* delta_x) / IMAGE_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}
