/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:37:04 by msumon            #+#    #+#             */
/*   Updated: 2024/06/28 10:15:00 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_empty(const char *str)
{
	while (*str != '\0')
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
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

int	height_until_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] == '1')
			break ;
		i++;
	}
	return (i);
}

int	map_parser(t_data *data)
{
	if (load_textures_and_colors(data, 0))
		return (1);
	if (map_without_textures(data->map, data))
		return (1);
	data->map_width = get_max_width(data->map);
	data->map_height = 0;
	while (data->map[data->map_height])
		data->map_height++;
	return (0);
}
