/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:36:10 by msumon            #+#    #+#             */
/*   Updated: 2024/06/28 12:50:48 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	space_checker(t_data *data, size_t x, int y)
{
	size_t	width;

	width = exact_width(data->map[y]);
	if (y == 0 && data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
		return (1);
	else if (y == data->map_height - 1 && data->map[y - 1][x] != '1'
		&& data->map[y - 1][x] != ' ')
		return (1);
	else if (y > 0 && y < data->map_height - 1 && x < width - 1 && x > 0)
	{
		data->map[y][x] = '1';
		if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != ' ')
				return (1);
		if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != ' ')
				return (1);
		if (ft_strlen(data->map[y]) <= ft_strlen(data->map[y - 1]) && ft_strlen(data->map[y]) <= ft_strlen(data->map[y + 1]))
		{
			if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ')
				return (1);
			if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
				return (1);
		}
		if (x > ft_strlen(data->map[y - 1]) && x <= ft_strlen(data->map[y + 1]))
		{
			if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
				return (1);
		}
		if (x < ft_strlen(data->map[y - 1]) && x > ft_strlen(data->map[y + 1]))
		{
			if (data->map[y - 1][x] != '1' && data->map[y + 1][x] != ' ')
				return (1);
		}
	}
	return (0);
}

int	empty_checker(t_data *data, int x, int y)
{
	if (y == 0 && (data->map[y + 1][x] == '\0' || data->map[y + 1][x] == '\n'))
	{
		return (1);
	}
	else if (y == data->map_height - 1 && (data->map[y - 1][x] == '\0'
		|| data->map[y - 1][x] == '\n'))
	{
		return (1);
	}
	else if (y != 0 && y != data->map_height - 1)
	{
		if ((data->map[y - 1][x] == ' ' || data->map[y - 1][x] == '\0'
				|| data->map[y - 1][x] == '\n'))
			return (1);
		else if ((data->map[y + 1][x] == ' ' || data->map[y + 1][x] == '\0'
				|| data->map[y + 1][x] == '\n'))
			return (1);
	}
	return (0);
}

int	valid_line_walls(t_data *data, int y)
{
	size_t	x;

	x = 0;
	while (data->map[y][x] != '\0')
	{
		if (data->map[y][x] == ' ')
		{
			if (space_checker(data, x, y))
				return (1);
		}
		else if (data->map[y][x] == '0')
		{
			if (empty_checker(data, x, y))
				return (1);
		}
		x++;
	}
	return (0);
}

int	valid_walls(t_data *data)
{
	int	y;

	if (!data || !data->map)
		return (1);
	y = 0;
	while (y < data->map_height - 1)
	{
		if (valid_line_walls(data, y))
			return (1);
		y++;
	}
	return (0);
}

int	valid_map(t_data *data)
{
	if (has_player(data))
		return (0);
	if (valid_chars(data))
		return (0);
	if (valid_borders(data))
		return (0);
	if (valid_walls(data))
		return (0);
	if (map_without_textures(data->map, data))
		return (0);
	data->map_width = ft_strlen(data->map[0]) - 1;
	data->map_height = 0;
	while (data->map[data->map_height])
		data->map_height++;
	return (1);
}
