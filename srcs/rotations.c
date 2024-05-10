/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:19:03 by msumon            #+#    #+#             */
/*   Updated: 2024/05/10 21:46:42 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_vec(double *beg_x, double *beg_y, double *end_x, double *end_y)
{
	const double	del_x = (*beg_x - *end_x);
	const double	del_y = (*beg_y - *end_y);

	*beg_x = (del_x * cos(ROTATE_SPEED) - del_y * sin(ROTATE_SPEED)) + *end_x;
	*beg_y = (del_x * sin(ROTATE_SPEED) + del_y * cos(ROTATE_SPEED)) + *end_y;
}

void	rotate_vec_back(double *beg_x, double *beg_y, double *end_x,
		double *end_y)
{
	const double	del_x = (*beg_x - *end_x);
	const double	del_y = (*beg_y - *end_y);

	*beg_x = (del_x * cos(-ROTATE_SPEED) - del_y * sin(-ROTATE_SPEED)) + *end_x;
	*beg_y = (del_x * sin(-ROTATE_SPEED) + del_y * cos(-ROTATE_SPEED)) + *end_y;
}

void	turn_left(t_data *data)
{
	rotate_vec_back(&data->dir.x, &data->dir.y, &data->player.x,
		&data->player.y);
	rotate_vec_back(&data->plane.x, &data->plane.y, &data->player.x,
		&data->player.y);
	rotate_vec_back(&data->plane2.x, &data->plane2.y, &data->player.x,
		&data->player.y);
}

void	turn_right(t_data *data)
{
	rotate_vec(&data->dir.x, &data->dir.y, &data->player.x, &data->player.y);
	rotate_vec(&data->plane.x, &data->plane.y, &data->player.x,
		&data->player.y);
	rotate_vec(&data->plane2.x, &data->plane2.y, &data->player.x,
		&data->player.y);
}
