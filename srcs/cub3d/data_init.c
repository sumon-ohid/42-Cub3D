/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:19:42 by msumon            #+#    #+#             */
/*   Updated: 2024/05/09 15:58:06 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mlx_data_init(t_data *data)
{
	data->win_width = 1440;
	data->win_height = 1080;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3d");
	if (!data->win)
		return (error("Window creation failed.\n"));
	return (0);
}

void set_default_values(t_data *data)
{
    data->no_texture = "././textures/SteelwallD.xpm";
    data->so_texture = "././textures/SteelwallD.xpm";
    data->we_texture = "././textures/SteelwallD.xpm";
    data->ea_texture = "././textures/SteelwallD.xpm";
    data->floor_color = "././textures/SteelwallD.xpm";
    data->ceiling_color = "././textures/SteelwallD.xpm";
}

void load_textures_and_colors(t_data *data, char *line)
{
    if (line[0] == 'N' && line[1] == 'O')
        data->no_texture = ft_strdup(line + 2);
    else if (line[0] == 'S' && line[1] == 'O')
        data->so_texture = ft_strdup(line + 2);
    else if (line[0] == 'W' && line[1] == 'E')
        data->we_texture = ft_strdup(line + 2);
    else if (line[0] == 'E' && line[1] == 'A')
        data->ea_texture = ft_strdup(line + 2);
    else if (line[0] == 'F')
        data->floor_color = ft_strdup(line + 1);
    else if (line[0] == 'C')
        data->ceiling_color = ft_strdup(line + 1);
    else
        set_default_values(data);
}

int load_map(t_data *data, int fd, int len)
{
    char *line;
    int i = 0;

    while (i < len && (line = get_next_line(fd)) != NULL)
    {
        data->map[i] = ft_strdup(line);
        load_textures_and_colors(data, line);
        i++;
        free(line);
    }
    data->map[i] = NULL;
    data->map_height = i;
    data->map_width = ft_strlen(line);
    return 0;
}

int	data_init(t_data *data, t_img *img, char *map_path)
{
    int		fd;
    int		len;

    len = map_line_count(map_path);
    img->width = IMG_W;
	img->height = IMG_H;
    data->map = malloc(sizeof(char *) * len + 1);
    if (!data->map || mlx_data_init(data))
        return (1);
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return (1);
    if (load_map(data, fd, len))
        return (1);
    close(fd);
    return (0);
}
