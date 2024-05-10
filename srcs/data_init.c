/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:19:42 by msumon            #+#    #+#             */
/*   Updated: 2024/05/10 23:55:42 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void set_default_values(t_data *data)
{
    data->no_texture = ft_strdup("./textures/masteryi.xpm");
    data->so_texture = ft_strdup("./textures/masteryi.xpm");
    data->we_texture = ft_strdup("./textures/masteryi.xpm");
    data->ea_texture = ft_strdup("./textures/masteryi.xpm");
    data->floor_color = 0x0000FF;
    data->ceiling_color = 0x800080;
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

int map_line_count(char *map)
{
    int fd;
    int i;
    char *line;

    i = 0;
    fd = open(map, O_RDONLY);
    if (fd < 0)
        return 0;
    line = get_next_line(fd);
    while (line > 0)
    {
        i++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return i;
}

int load_map(t_data *data, char *map_path, t_img *img)
{
    (void)img;
    char *line;
    int fd;
    int len;
    int i;
    
    i = 0;
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return 1;
    data->map = malloc(sizeof(char *) * (map_line_count(map_path) + 1));
    if (!data->map)
        return 1;
    len = map_line_count(map_path);
    line = get_next_line(fd); // protect
    while (i < len && line != NULL)
    {
        data->map[i] = ft_strdup(line);
        i++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    data->map[i] = NULL;
    close(fd);
    //load_textures_and_colors(data);
    set_default_values(data);
    data->map_width = ft_strlen(data->map[0]);
    data->map_height = i;
    return 0;
}

int	data_init(t_data *data, char *map_path)
{
    // Initialize all fields to default values
    data->img = NULL;
    data->no_img = NULL;
    data->so_img = NULL;
    data->we_img = NULL;
    data->ea_img = NULL;
    data->player = (t_player){0};
    data->dir = (t_point){0};
    data->plane = (t_point){0};
    data->plane2 = (t_point){0};
    data->mlx = NULL;
    data->win = NULL;
    data->win_width = 0;
    data->win_height = 0;
    data->no_texture = NULL;
    data->so_texture = NULL;
    data->we_texture = NULL;
    data->ea_texture = NULL;
    data->sprite_texture = NULL;
    data->floor_color = 0;
    data->ceiling_color = 0;
    data->map = NULL;
    data->map_width = 0;
    data->map_height = 0;
    data->ray_num = 0;
    data->ray_angle = 0;
    data->ty_step = 0.0;
    if (load_map(data, map_path, data->img))
        return (1);
    return (0);
}
