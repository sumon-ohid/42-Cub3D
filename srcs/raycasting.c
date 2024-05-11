/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:29:21 by msumon            #+#    #+#             */
/*   Updated: 2024/05/11 21:45:38 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	add_img_pixel(t_data *data, t_point p, int x, double y)
{
    double	tx;
    double	ty;
    int		i;

    tx = (int)(p.x) % IMAGE_SIZE;
    ty = (int)(p.y) % IMAGE_SIZE;
    i = WIN_H / 2 - x - 1;
    while (++i < WIN_H / 2 + x && i < WIN_H)
    {
        if ((int)tx == 0)
            data->img->pixels[WIN_W * i + data->ray_num]
                = data->ea_img->pixels[(int)y * IMAGE_SIZE + (int)ty];
        else if ((int)ty == 0)
            data->img->pixels[WIN_W * i
                + data->ray_num] = data->so_img->pixels[(int)y * IMAGE_SIZE
                + IMAGE_SIZE - 1 - (int)tx];
        else if ((int)tx == IMAGE_SIZE - 1)
            data->img->pixels[WIN_W * i
                + data->ray_num] = data->we_img->pixels[(int)y * IMAGE_SIZE
                + IMAGE_SIZE - 1 - (int)ty];
        else if ((int)ty == IMAGE_SIZE - 1)
            data->img->pixels[WIN_W * i + data->ray_num]
                = data->no_img->pixels[(int)y * IMAGE_SIZE + (int)tx];
        y += data->coordinate_y;
    }
}

void	draw_texture(t_data *data, double dist, t_point p)
{
	int		x;
	double	ty_off;
	double	y;

	x = (int)(IMAGE_SIZE * WIN_H / 2 / dist);
	ty_off = 0;
	data->coordinate_y = 1024.0 / (double)(2 * x);
	if (x > WIN_H / 2)
	{
		ty_off = (x - WIN_H / 2);
		x = WIN_H / 2;
	}
	y = ty_off * data->coordinate_y;
	add_img_pixel(data, p, x, y);
}

void	draw_if_empty(t_data *data, t_point p1, double dx)
{
	if (data->map[(int)p1.y / IMAGE_SIZE]
		[(int)p1.x / IMAGE_SIZE] == EMPTY)
		p1.x -= dx;
	draw_texture(data, sqrt(pow(data->player.y - p1.y, 2) + pow(data->player.x
				- p1.x, 2)) * cos(abs(data->ray_angle)), p1);
}

void	draw_line(t_data *data, t_point p1, t_point p2, double length)
{
	double	dx;
	double	dy;
	double	max;

	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	max = fmax(fabs(dx), fabs(dy));
	dy /= max;
	dx /= max;
	p2.x += dx * length;
	p2.y += dy * length;
	while (1)
	{
		if (IMAGE_SIZE * data->map_width > p1.x && IMAGE_SIZE
			* data->map_height > p1.y && data->map[(int)p1.y
				/ IMAGE_SIZE][(int)p1.x / IMAGE_SIZE] != EMPTY)
		{
			draw_if_empty(data, p1, dx);
			break ;
		}
		p1.x += dx;
		p1.y += dy;
	}
}

void	raycast(t_data *data, t_point dir, double length)
{
	t_point	p;
	double	del_x;
	double	del_y;

	data->ray_num = -1;
	p.x = data->player.x;
	p.y = data->player.y;
	p.color = 0x5500FF00;
	del_x = (dir.x - data->player.x);
	del_y = (dir.y - data->player.y);
	dir.x = (del_x * cos(-FOV / 2) - del_y * sin(-FOV / 2)) + data->player.x;
	dir.y = (del_x * sin(-FOV / 2) + del_y * cos(-FOV / 2)) + data->player.y;
	data->ray_angle = -FOV / 2;
	while (++data->ray_num < WIN_W)
	{
		draw_line(data, p, dir, length);
		del_x = (dir.x - data->player.x);
		del_y = (dir.y - data->player.y);
		dir.x = (del_x * cos(FOV / WIN_W) - del_y * sin(FOV / WIN_W))
			+ data->player.x;
		dir.y = (del_x * sin(FOV / WIN_W) + del_y * cos(FOV / WIN_W))
			+ data->player.y;
		data->ray_angle += FOV / WIN_W;
	}
}
