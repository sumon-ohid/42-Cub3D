/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:53:23 by msumon            #+#    #+#             */
/*   Updated: 2024/06/27 10:02:41 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_hook(int key, t_data *data)
{
	if (key == ESC)
		close_game(data);
	else if (key == W_KEY)
		move_forward(data);
	else if (key == A_KEY)
		move_left(data);
	else if (key == S_KEY)
		move_backward(data);
	else if (key == D_KEY)
		move_right(data);
	else if (key == LEFT_ARROW)
		turn_left(data);
	else if (key == RIGHT_ARROW)
		turn_right(data);
	return (0);
}

int	handle_images(t_data *data)
{
	create_new_image(data, WIN_W, WIN_H);
	create_background(data);
	raycast(data, data->dir, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img_ptr);
	return (0);
}

int	start_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	if (allocate_textures(data))
		return (1);
	if (create_textures(data))
		return (1);
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "Cub3D");
	if (!data->win)
		return (1);
	mlx_hook(data->win, 2, 1L, &key_hook, data);
	mlx_hook(data->win, CROSS_KEY, 0L, &close_game, data);
	mlx_loop_hook(data->mlx, &handle_images, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (error("Invalid number of arguments.\n"));
	if (data_init(&data, av[1]))
		return (error("Data initialization failed.\n"));
	if (map_parser(&data))
	{
		clean_data(&data);
		return (error("Map parsing failed.\n"));
	}
	if (!valid_map(&data))
	{
		clean_data(&data);
		return (error("Invalid map.\n"));
	}
	if (start_game(&data))
	{
		clean_data(&data);
		return (error("Game start failed.\n"));
	}
	clean_data(&data);
	return (0);
}
