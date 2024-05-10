/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:53:23 by msumon            #+#    #+#             */
/*   Updated: 2024/05/10 23:57:09 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	clean_input_structure(t_data *data)
{
	if (data->no_texture)
	{
		free(data->no_texture);
		data->no_texture = NULL;
	}
	if (data->so_texture)
	{
		free(data->so_texture);
		data->no_texture = NULL;
	}
	if (data->we_texture)
	{
		free(data->we_texture);
		data->no_texture = NULL;
	}
	if (data->ea_texture)
	{
		free(data->ea_texture);
		data->no_texture = NULL;
	}
	if (data->map)
	{
		free_array(data->map);
		data->map = NULL;
	}
}

void	clean_data(t_data *data)
{
	if (data->ea_img && data->ea_img->img_ptr)
		mlx_destroy_image(data->mlx, data->ea_img->img_ptr);
	if (data->we_img && data->we_img->img_ptr)
		mlx_destroy_image(data->mlx, data->we_img->img_ptr);
	if (data->so_img && data->so_img->img_ptr)
		mlx_destroy_image(data->mlx, data->so_img->img_ptr);
	if (data->no_img && data->no_img->img_ptr)
		mlx_destroy_image(data->mlx, data->no_img->img_ptr);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->img)
		free(data->img);
	if (data->ea_img)
		free(data->ea_img);
	if (data->no_img)
		free(data->no_img);
	if (data->so_img)
		free(data->so_img);
	if (data->we_img)
		free(data->we_img);
	clean_input_structure(data);
}

int	error(char *str)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("Error:\n", fd);
	ft_putstr_fd(str, fd);
	return (0);
}

int	close_game(t_data *data)
{
	clean_data(data);
	exit(0);
}

int key_hook(int key, t_data *data)
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
	raycast(data, data->dir, 1);
	mlx_put_image_to_window(data->mlx, data->win,
		data->img->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx, data->img->img_ptr);
	return (0);
}

int	alloc_textures(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		return (1);
	data->img->img_ptr = NULL;
	data->ea_img = (t_img *)malloc(sizeof(t_img));
	if (!data->ea_img)
		return (1);
	data->ea_img->img_ptr = NULL;
	data->no_img = (t_img *)malloc(sizeof(t_img));
	if (!data->no_img)
		return (1);
	data->no_img->img_ptr = NULL;
	data->so_img = (t_img *)malloc(sizeof(t_img));
	if (!data->so_img)
		return (1);
	data->so_img->img_ptr = NULL;
	data->we_img = (t_img *)malloc(sizeof(t_img));
	if (!data->we_img)
		return (1);
	data->we_img->img_ptr = NULL;
	return (0);
}

int	start_game(t_data *data)
{
	if (alloc_textures(data))
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, WIN_W, 	WIN_H, "Cub3D");
	if (!data->mlx)
		return (1);
	if (create_textures(data))
		return (1);
	mlx_hook(data->win, 2, 1L, &key_hook, data);
	mlx_hook(data->win, CROSS_KEY, 0L, &close_game, data);
	mlx_loop_hook(data->mlx, &handle_images, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
    t_data  data;

	if (ac != 2)
		return (error("Invalid number of arguments.\n"));
	// if (map_validation(av[1], 0)) // need to implement texturing and color validation
	// 	return (error("Invalid map.\n"));
    if (data_init(&data, av[1]))
        return (error("Data initialization failed.\n"));
	if (is_valid_map(&data))
		return (error("Invalid map.\n"));
	if (start_game(&data))
		return (error("Game start failed.\n"));
    clean_data(&data);
	return (0);
}
