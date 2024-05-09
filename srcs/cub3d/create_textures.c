/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:02:07 by msumon            #+#    #+#             */
/*   Updated: 2024/05/09 16:11:54 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img image_loader(void *mlx, char *file)
{
    t_img img;

    img.img_ptr = mlx_xpm_file_to_image(mlx, file, &img.width, &img.height);
    if (!img.img_ptr)
    {
        error("Image loading failed.\n");
        exit (1);
    }
    img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
    return (img);
}

void mlx_put_image(t_data *data, t_img *img, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, img->img_ptr, x * TILE_SIZE, y * TILE_SIZE);
}

int put_textures_on_map(t_data *data)
{
    int x;
    int y;

    y = 0;
    while(data->map[y])
    {
        x = 0;
        while(data->map[y][x])
        {
            if (data->map[y][x] == '1')
                mlx_put_image(data, &data->floor_img, x, y);
            else if (data->map[y][x] == '0')
                mlx_put_image(data, &data->ceiling_img, x, y);
            else if (data->map[y][x] == 'N')
                mlx_put_image(data, &data->no_img, x, y);
            x++;
        }
        y++;
    }
    return (0);
}

int create_textures(t_data *data)
{
    data->floor_img = image_loader(data->mlx, data->floor_color);
    data->ceiling_img = image_loader(data->mlx, "././textures/ceiling.xpm");
    data->no_img = image_loader(data->mlx, "././textures/greystonewall.xpm");
    data->so_img = image_loader(data->mlx, data->so_texture);
    data->we_img = image_loader(data->mlx, data->we_texture);
    data->ea_img = image_loader(data->mlx, data->ea_texture);
    put_textures_on_map(data);
    return (0);
}
