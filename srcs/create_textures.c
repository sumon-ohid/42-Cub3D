/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:37:43 by vsharma           #+#    #+#             */
/*   Updated: 2024/06/21 11:51:21 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_no_img(t_data *data, int *x, int *y)
{
	data->no_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->no_texture,
			x, y);
	if (!data->no_img->img_ptr || *x != IMG_SIZE || *y != IMG_SIZE)
	{
		error("no_img failed\n");
		close_game(data);
		return (1);
	}
	data->no_img->pixels = (int *)mlx_get_data_addr(data->no_img->img_ptr,
			&data->no_img->bits_per_pixel, &data->no_img->line_length,
			&data->no_img->endian);
	return (0);
}

int	create_ea_img(t_data *data, int *x, int *y)
{
	data->ea_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->ea_texture,
			x, y);
	if (!data->ea_img->img_ptr || *x != IMG_SIZE || *y != IMG_SIZE)
	{
		error("ea_img failed\n");
		close_game(data);
		return (1);
	}
	data->ea_img->pixels = (int *)mlx_get_data_addr(data->ea_img->img_ptr,
			&data->ea_img->bits_per_pixel, &data->ea_img->line_length,
			&data->ea_img->endian);
	return (0);
}

int	create_so_img(t_data *data, int *x, int *y)
{
	data->so_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->so_texture,
			x, y);
	if (!data->so_img->img_ptr || *x != IMG_SIZE || *y != IMG_SIZE)
	{
		error("so_img failed\n");
		close_game(data);
		return (1);
	}
	data->so_img->pixels = (int *)mlx_get_data_addr(data->so_img->img_ptr,
			&data->so_img->bits_per_pixel, &data->so_img->line_length,
			&data->so_img->endian);
	return (0);
}

int	create_we_img(t_data *data, int *x, int *y)
{
	data->we_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->we_texture,
			x, y);
	if (!data->we_img->img_ptr || *x != IMG_SIZE || *y != IMG_SIZE)
	{
		error("we_img failed\n");
		close_game(data);
		return (1);
	}
	data->we_img->pixels = (int *)mlx_get_data_addr(data->we_img->img_ptr,
			&data->we_img->bits_per_pixel, &data->we_img->line_length,
			&data->we_img->endian);
	return (0);
}

int	create_textures(t_data *data)
{
	int	x;
	int	y;

	x = IMG_SIZE;
	y = IMG_SIZE;
	if (create_no_img(data, &x, &y))
		return (1);
	if (create_ea_img(data, &x, &y))
		return (1);
	if (create_so_img(data, &x, &y))
		return (1);
	if (create_we_img(data, &x, &y))
		return (1);
	return (0);
}

/*
int	create_textures(t_data *data)
{
	if (create_image(data))
	{
		return (1);
	}
	return (0);
} */
/*int	create_more_image(t_data *data, int *x, int *y)
{
	data->so_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->so_texture,
			x, y);
	if (!data->so_img->img_ptr || *x != IMG_SIZE || *y != IMG_SIZE)
	{
		error("so_img failed\n");
		close_game(data);
		return (1);
	}
	data->so_img->pixels = (int *)mlx_get_data_addr(data->so_img->img_ptr,
			&data->so_img->bits_per_pixel, &data->so_img->line_length,
			&data->so_img->endian);
	data->we_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->we_texture,
			x, y);
	if (!data->we_img->img_ptr || *x != IMG_SIZE || *y != IMG_SIZE)
	{
		error("we_img failed\n");
		close_game(data);
		return (1);
	}
	data->we_img->pixels = (int *)mlx_get_data_addr(data->we_img->img_ptr,
			&data->we_img->bits_per_pixel, &data->we_img->line_length,
			&data->we_img->endian);
	return (0);
}

int	create_image(t_data *data)
{
	int	x;
	int	y;

	x = IMG_SIZE;
	y = IMG_SIZE;
	data->no_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->no_texture,
			&x, &y);
	if (!data->no_img->img_ptr || x != IMG_SIZE || y != IMG_SIZE)
	{
		error("no_img failed\n");
		close_game(data);
		return (1);
	}
	data->no_img->pixels = (int *)mlx_get_data_addr(data->no_img->img_ptr,
			&data->no_img->bits_per_pixel, &data->no_img->line_length,
			&data->no_img->endian);
	data->ea_img->img_ptr = mlx_xpm_file_to_image(data->mlx, data->ea_texture,
			&x, &y);
	if (!data->ea_img->img_ptr || x != IMG_SIZE || y != IMG_SIZE)
	{
		error("ea_img failed\n");
		close_game(data);
		return (1);
	}
	data->ea_img->pixels = (int *)mlx_get_data_addr(data->ea_img->img_ptr,
			&data->ea_img->bits_per_pixel, &data->ea_img->line_length,
			&data->ea_img->endian);
	if (create_more_image(data, &x, &y))
		return (1);
	return (0);
}*/