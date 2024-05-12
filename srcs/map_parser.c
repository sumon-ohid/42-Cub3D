/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:37:04 by msumon            #+#    #+#             */
/*   Updated: 2024/05/12 11:01:15 by msumon           ###   ########.fr       */
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

char *remove_space(char *line)
{
    char *new_line;
    int i;
    int j;

    i = 0;
    j = 0;
    new_line = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
    while (line[i])
    {
        if (line[i] != ' ')
        {
            new_line[j] = line[i];
            j++;
        }
        i++;
    }
    new_line[j] = '\0';
    return (new_line);
}

int load_textures_and_colors(t_data *data)
{
    char *line;
    int i;
    int r, g, b = 0;
    
    i = 0;
    while (data->map[i] && data->map[i][0] != '1')
    {
        line = remove_space(data->map[i]);
        if (line[0] == 'N' && line[1] == 'O')
            data->no_texture = ft_strdup(line + 2);
        else if (line[0] == 'S' && line[1] == 'O')
            data->so_texture = ft_strdup(line + 2);
        else if (line[0] == 'W' && line[1] == 'E')
            data->we_texture = ft_strdup(line + 2);
        else if (line[0] == 'E' && line[1] == 'A')
            data->ea_texture = ft_strdup(line + 2);
        else if (line[0] == 'F')
        {
            r = ft_atoi(line + 1);
            g = ft_atoi(ft_strchr(line + 1, ',') + 1);
            b = ft_atoi(ft_strrchr(line + 1, ',') + 1);
            data->floor_color = (r << 16) + (g << 8) + b;
        }
        else if (line[0] == 'C')
        {
            r = ft_atoi(line + 1);
            g = ft_atoi(ft_strchr(line + 1, ',') + 1);
            b = ft_atoi(ft_strrchr(line + 1, ',') + 1);
            data->ceiling_color = (r << 16) + (g << 8) + b;
        }
        i++;
    }
    return 0;
}

int map_parser(t_data *data)
{
    if (load_textures_and_colors(data))
        return (1);
    else
        set_default_values(data);
    return 0;
}
