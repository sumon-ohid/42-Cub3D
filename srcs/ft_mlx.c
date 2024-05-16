/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:21:52 by msumon            #+#    #+#             */
/*   Updated: 2024/05/16 11:21:26 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_camera(t_data *data, int x, int y)
{
	data->dir.x = x * IMAGE_SIZE + IMAGE_SIZE / 2 - DIR_L * (data->map[y][x] == 'W') + DIR_L * (data->map[y][x] == 'E');
	data->dir.y = y * IMAGE_SIZE + IMAGE_SIZE / 2 - DIR_L * (data->map[y][x] == 'N') + DIR_L * (data->map[y][x] == 'S');
	data->dir.color = 0xFF0000;
	data->plane.color = 0xFFFF00;
}

void	create_new_image(t_data *data, int width, int height)
{
	data->img->img_ptr = mlx_new_image(data->mlx, width, height);
	data->img->pixels = (int *)mlx_get_data_addr(data->img->img_ptr,
			&data->img->bits_per_pixel, &data->img->line_length,
			&data->img->endian);
	data->img->bits_per_pixel /= 8;
}
void	create_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIN_W)
	{
		y = 0;
		while (y < WIN_H / 2)
		{
			data->img->pixels[WIN_W * y + x] = data->ceiling_color;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < WIN_W)
	{
		y = WIN_H / 2;
		while (y < WIN_H)
		{
			data->img->pixels[WIN_W * y + x] = data->floor_color;
			y++;
		}
		x++;
	}
}
