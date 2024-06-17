/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:37:04 by msumon            #+#    #+#             */
/*   Updated: 2024/06/17 14:38:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	parse_color(char *line, int i)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;
	int		ret;

	ret = 0;
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_array(rgb);
		return (0);
	}
	while (rgb[i])
		i++;
	if (i != 3)
	{
		error("Invalid Color.\n");
		free_array(rgb);
		return (0);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		error("Invalid color\n");
		free_array(rgb);
		return (0);
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

char	*copy_until_newline(char *line)
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

int ft_rtn(char *line)
{
	free(line);
	return (1);
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
		{
			if (data->no_texture)
				return (ft_rtn(line));
			data->no_texture = copy_until_newline(line + 2);  
			if (!data->no_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			if (data->so_texture)
				return (ft_rtn(line));
			data->so_texture = copy_until_newline(line + 2);
			if (!data->so_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			if (data->we_texture)
				return (ft_rtn(line));
			data->we_texture = copy_until_newline(line + 2);
			if (!data->we_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			if (data->ea_texture)
				return (ft_rtn(line));
			data->ea_texture = copy_until_newline(line + 2);
			if (!data->ea_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'F')
		{
			if (data->floor_color)
				return (ft_rtn(line));
			data->floor_color = parse_color(line + 1, 0);
			if (!data->floor_color)
				return (ft_rtn(line));
		}
		else if (line[0] == 'C')
		{
			if (data->ceiling_color)
				return (ft_rtn(line));
			data->ceiling_color = parse_color(line + 1, 0);
			if (!data->ceiling_color)
				return (ft_rtn(line));
		}
		else if (line[0] == ' ' || line[0] == '\n')
			printf("");
		else
			return(ft_rtn(line));
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
	char	*line;

	i = 0;
	j = 0;
	new_map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!new_map)
		return (1);
	while (map[i])
	{
		line = remove_space(map[i]);
		if (line[0] == '1')
		{
			free(line);  // vs: free line
			break ;
		}
		free (line); // vs:  free line
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

int	get_max_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	map_parser(t_data *data)
{
	if (load_textures_and_colors(data))
		return (1);
	if (map_without_textures(data->map, data))
		return (1);
	data->map_width = get_max_width(data->map);
	data->map_height = 0;
	while (data->map[data->map_height])
		data->map_height++;
	return (0);
}
