/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:37:04 by msumon            #+#    #+#             */
/*   Updated: 2024/05/11 22:09:32 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_default_values(t_data *data)
{
    data->no_texture = ft_strdup("./textures/wantedwall.xpm");
    data->so_texture = ft_strdup("./textures/wall.xpm");
    data->we_texture = ft_strdup("./textures/wall.xpm");
    data->ea_texture = ft_strdup("./textures/wall.xpm");
    data->floor_color = 0x93917C;
    data->ceiling_color = 0x413839; //0x00BFFF;
}

int load_textures_and_colors(t_data *data)
{
    char *line;
    int i;
    
    i = 0;
    while (i < 8)
    {
        line = data->map[i];
        if (line[0] == 'N' && line[1] == 'O')
            data->no_texture = ft_strdup(line + 2);
        else if (line[0] == 'S' && line[1] == 'O')
            data->so_texture = ft_strdup(line + 2);
        else if (line[0] == 'W' && line[1] == 'E')
            data->we_texture = ft_strdup(line + 2);
        else if (line[0] == 'E' && line[1] == 'A')
            data->ea_texture = ft_strdup(line + 2);
        else if (line[0] == 'F')
            data->floor_color = ft_atoi(line + 1);
        else if (line[0] == 'C')
            data->ceiling_color = ft_atoi(line + 1);
        i++;
    }
    return 0;
}

int map_parser(t_data *data)
{
    set_default_values(data);
    return 0;
}
