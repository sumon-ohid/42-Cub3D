/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:37:04 by msumon            #+#    #+#             */
/*   Updated: 2024/05/16 11:16:20 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_default_values(t_data *data)
{
	data->no_texture = ft_strdup("./textures/wantedwall.xpm");
	data->so_texture = ft_strdup("./textures/wall.xpm");
	data->we_texture = ft_strdup("./textures/wall.xpm");
	data->ea_texture = ft_strdup("./textures/wall.xpm");
	data->floor_color = 0x93917C;
	data->ceiling_color = 0x413839;
}

char	*remove_space(char *line)
{
    int		i;
    int		j;
    char	*new_line;

    i = 0;
    j = 0;
    new_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
    if (!new_line)
        return (NULL);
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

int	parse_color(char *line, t_data *data)
{
    char **rgb;
	int	r;
	int	g;
	int	b;
	int	ret;

	ret = 0;
    rgb = ft_split(line, ',');
    if (!rgb)
        return (0);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		error("Invalid color\n");
		free_array(data->map);
		exit(1);
	}
	ret = (r << 16) + (g << 8) + b;
    free_array(rgb);
	return (ret);
}

int	texture_end_xpm(char *line)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = len - 5;
	if (ft_strncmp(line + i, ".xpm", 4))
		return (1);
	return (0);
}

char *copy_until_newline(char *line)
{
    int		i;
    int		j;
    char	*new_line;

    i = 0;
    j = 0;
    new_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
    if (!new_line)
        return (NULL);
    while (line[i] && line[i] != '\n')
    {
        new_line[j] = line[i];
        i++;
        j++;
    }
    new_line[j] = '\0';
    return (new_line);
}

int	load_textures_and_colors(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (data->map[i] && data->map[i][0] != '1')
	{
		line = remove_space(data->map[i]);
        if (!line)
            return (1);
        if (line[0] == 'N' && line[1] == 'O')
			data->no_texture = copy_until_newline(line + 2);        
        if (line[0] == 'S' && line[1] == 'O')
			data->so_texture = copy_until_newline(line + 2);
        if (line[0] == 'W' && line[1] == 'E')
			data->we_texture = copy_until_newline(line + 2);
        if (line[0] == 'E' && line[1] == 'A')
			data->ea_texture = copy_until_newline(line + 2);
        if (line[0] == 'F')
			data->floor_color = parse_color(line + 1, data);
        if (line[0] == 'C')
            data->ceiling_color = parse_color(line + 1, data);
        free(line);
		i++;
	}
	return (0);
}

int	map_without_textures(char **map, t_data *data)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!new_map)
		return (1);
	while (map[i])
	{
		if (map[i][0] == '1')
			break ;
		i++;
	}
	while (map[i])
	{
		new_map[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	new_map[j] = NULL;
	free_array(data->map);
	data->map = new_map;
	return (0);
}

int	map_parser(t_data *data)
{
    if (map_init(data, data->map_path, data->map_height))
        return (1);
	if (load_textures_and_colors(data))
        return (1);
	if (map_without_textures(data->map, data))
		return (1);
    data->map_width = ft_strlen(data->map[0]) - 1;
    data->map_height = 0;
    while(data->map[data->map_height])
        data->map_height++;
	return (0);
}
