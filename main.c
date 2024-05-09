/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:53:23 by msumon            #+#    #+#             */
/*   Updated: 2024/05/09 12:59:06 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include "mlx.h"

void   clean_data(t_data *data)
{
    if (data->no_texture)
        free(data->no_texture);
    if (data->so_texture)
        free(data->so_texture);
    if (data->we_texture)
        free(data->we_texture);
    if (data->ea_texture)
        free(data->ea_texture);
    free_array(data->map);
    mlx_destroy_window(data->mlx, data->win);
    free(data->mlx);
}

int	error(char *str)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("Error.\n", fd);
	ft_putstr_fd(str, fd);
	return (0);
}

int key_hook(int keycode, t_data *data)
{
    (void)data;
    if (keycode == 53)
    {
        //clean_data(data);
        exit(0);
    }
    return (0);
}

int	main(int ac, char **av)
{
    t_data  data;
    t_img   img;

	if (ac != 2)
		return (error("Invalid number of arguments.\n"));
	if (map_validation(av[1], 0)) // need to implement texturing and color validation
		return (error("Invalid map.\n"));
    if (data_init(&data, &img, av[1]))
        return (error("Data initialization failed.\n"));
    img.img_path = "../textures/floor.xpm";
    create_textures(&data);
    mlx_key_hook(data.win, key_hook, &data);    
    mlx_loop(&data.mlx);
    //clean_data(&data);
	return (0);
}
