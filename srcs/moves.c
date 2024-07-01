/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:08:45 by msumon            #+#    #+#             */
/*   Updated: 2024/07/01 12:59:55 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_data *data)
{
	const double	delta_x = (data->dir.x - data->player->x) / DIR_L;
	const double	delta_y = (data->dir.y - data->player->y) / DIR_L;

	if (data->map[(int)data->player->y / IMG_SIZE][(int)(data->player->x + SPEED
		* delta_x) / IMG_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player->y + SPEED * delta_y)
		/ IMG_SIZE][(int)(data->player->x / IMG_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}

void	move_backward(t_data *data)
{
	const double	delta_x = -(data->dir.x - data->player->x) / DIR_L;
	const double	delta_y = -(data->dir.y - data->player->y) / DIR_L;

	if (data->map[(int)data->player->y / IMG_SIZE][(int)(data->player->x + SPEED
		* delta_x) / IMG_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player->y + SPEED * delta_y)
		/ IMG_SIZE][(int)(data->player->x / IMG_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}

void	move_left(t_data *data)
{
	const double	delta_x = (data->dir.y - data->player->y) / DIR_L;
	const double	delta_y = -(data->dir.x - data->player->x) / DIR_L;

	if (data->map[(int)data->player->y / IMG_SIZE][(int)(data->player->x + SPEED
		* delta_x) / IMG_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player->y + SPEED * delta_y)
		/ IMG_SIZE][(int)(data->player->x / IMG_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}

// delta_x and delta_y are the difference between
// the player's position and the direction
// dir.x - player.x / DIR_L and dir.y - player.y / DIR_L
// are the normalized direction vectors
void	move_right(t_data *data)
{
	const double	delta_x = -(data->dir.y - data->player->y) / DIR_L;
	const double	delta_y = (data->dir.x - data->player->x) / DIR_L;

	if (data->map[(int)data->player->y / IMG_SIZE][(int)(data->player->x + SPEED
		* delta_x) / IMG_SIZE] == EMPTY)
		update_x_positions(data, delta_x);
	if (data->map[(int)(data->player->y + SPEED * delta_y)
		/ IMG_SIZE][(int)(data->player->x / IMG_SIZE)] == EMPTY)
		update_y_positions(data, delta_y);
}
