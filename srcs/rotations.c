/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:19:03 by msumon            #+#    #+#             */
/*   Updated: 2024/06/11 14:32:44 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_vector(double *start_x, double *start_y, double *end_x,
		double *end_y)
{
	const double	delta_x = (*start_x - *end_x);
	const double	delta_y = (*start_y - *end_y);

	*start_x = (delta_x * cos(ROTATE_ANGLE) - delta_y * sin(ROTATE_ANGLE))
		+ *end_x;
	*start_y = (delta_x * sin(ROTATE_ANGLE) + delta_y * cos(ROTATE_ANGLE))
		+ *end_y;
}

void	rotate_vector_back(double *start_x, double *start_y, double *end_x,
		double *end_y)
{
	const double	delta_x = (*start_x - *end_x);
	const double	delta_y = (*start_y - *end_y);

	*start_x = (delta_x * cos(-ROTATE_ANGLE) - delta_y * sin(-ROTATE_ANGLE))
		+ *end_x;
	*start_y = (delta_x * sin(-ROTATE_ANGLE) + delta_y * cos(-ROTATE_ANGLE))
		+ *end_y;
}

void	turn_left(t_data *data)
{
	rotate_vector_back(&data->dir.x, &data->dir.y, &data->player.x,
		&data->player.y);
	rotate_vector_back(&data->plane.x, &data->plane.y, &data->player.x,
		&data->player.y);
	rotate_vector_back(&data->plane2.x, &data->plane2.y, &data->player.x,
		&data->player.y);
}

void	turn_right(t_data *data)
{
	rotate_vector(&data->dir.x, &data->dir.y, &data->player.x, &data->player.y);
	rotate_vector(&data->plane.x, &data->plane.y, &data->player.x,
		&data->player.y);
	rotate_vector(&data->plane2.x, &data->plane2.y, &data->player.x,
		&data->player.y);
}
