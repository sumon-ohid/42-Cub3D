/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:12:02 by msumon            #+#    #+#             */
/*   Updated: 2024/06/12 11:37:33 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

#define MMAP_SIZE 16
#define MMAP_EMPTY 0xFFFFFF
#define MMAP_WALL 0x000000
#define MMAP_PLAYER 0xFF0000
#define MMAP_BORDER 0x300603

void	draw_cell(t_data *data, int x, int y, int color)
{
	const int	x1 = x + MMAP_SIZE;
	const int	y1 = y + MMAP_SIZE;

	while (x < x1)
	{
		y = y1 - MMAP_SIZE;
		while (y < y1)
		{
			data->img->pixels[WIN_W * y + x] = color;
			y++;
		}
		x++;
	}
}

void	cub_minimap(t_data *data)
{
	int	x;
	int	y;
	int	start_y;

	start_y = WIN_H - data->map_height * MMAP_SIZE - 10;
	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		data->map_width = ft_strlen(data->map[y]);
		while (++x < data->map_width)
		{
			if (data->map[y][x] == '1')
				draw_cell(data, x * MMAP_SIZE, (y * MMAP_SIZE) + start_y,
					MMAP_WALL);
			else if (data->map[y][x] == '0')
				draw_cell(data, (x * MMAP_SIZE), (y * MMAP_SIZE) + start_y,
					MMAP_EMPTY);
		}
	}
	draw_cell(data, data->player.x / IMAGE_SIZE * MMAP_SIZE, (data->player.y
			/ IMAGE_SIZE * MMAP_SIZE) + start_y, MMAP_PLAYER);
}
