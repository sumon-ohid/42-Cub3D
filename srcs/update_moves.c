/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:32:37 by msumon            #+#    #+#             */
/*   Updated: 2024/06/21 13:03:50 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_x_positions(t_data *data, double delta_x)
{
	data->player->x += SPEED * delta_x;
	data->dir.x += SPEED * delta_x;
	data->plane.x += SPEED * delta_x;
	data->plane2.x += SPEED * delta_x;
}

void	update_y_positions(t_data *data, double delta_y)
{
	data->player->y += SPEED * delta_y;
	data->dir.y += SPEED * delta_y;
	data->plane.y += SPEED * delta_y;
	data->plane2.y += SPEED * delta_y;
}
