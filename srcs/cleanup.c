/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:22:23 by msumon            #+#    #+#             */
/*   Updated: 2024/05/11 21:23:04 by msumon           ###   ########.fr       */
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
	free(data->mlx);
	free(data->win);
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
