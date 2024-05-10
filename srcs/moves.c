/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:08:45 by msumon            #+#    #+#             */
/*   Updated: 2024/05/10 21:46:30 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_data *data)
{
	const double	delta_x = (data->dir.x - data->player.x) / DIR_L;
	const double	delta_y = (data->dir.y - data->player.y) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == EMPTY)
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
}

void	move_backward(t_data *data)
{
	const double	delta_x = -(data->dir.x - data->player.x) / DIR_L;
	const double	delta_y = -(data->dir.y - data->player.y) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == EMPTY)
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
}

void	move_left(t_data *data)
{
	const double	delta_x = (data->dir.y - data->player.y) / DIR_L;
	const double	delta_y = -(data->dir.x - data->player.x) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == EMPTY)
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
}

void	move_right(t_data *data)
{
	const double	delta_x = -(data->dir.y - data->player.y) / DIR_L;
	const double	delta_y = (data->dir.x - data->player.x) / DIR_L;

	if (data->map[(int)data->player.y / IMAGE_SIZE][(int)(data->player.x
		+ SPEED * delta_x) / IMAGE_SIZE] == EMPTY)
	{
		data->player.x += SPEED * delta_x;
		data->dir.x += SPEED * delta_x;
		data->plane.x += SPEED * delta_x;
		data->plane2.x += SPEED * delta_x;
	}
	if (data->map[(int)(data->player.y + SPEED * delta_y)
		/ IMAGE_SIZE][(int)(data->player.x / IMAGE_SIZE)] == EMPTY)
	{
		data->player.y += SPEED * delta_y;
		data->dir.y += SPEED * delta_y;
		data->plane.y += SPEED * delta_y;
		data->plane2.y += SPEED * delta_y;
	}
}
