/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:12:40 by msumon            #+#    #+#             */
/*   Updated: 2024/06/26 10:34:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	has_char(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	has_player(t_data *data)
{
	int	x;
	int	y;
	int	width;

	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		width = ft_strlen(data->map[y]);
		while (++x < width)
		{
			if (has_char("NSWE", data->map[y][x]))
			{
				if (data->player->player)
					return (1);
				data->player->player = data->map[y][x];
				data->player->x = x * IMG_SIZE + IMG_SIZE / 2;
				data->player->y = y * IMG_SIZE + IMG_SIZE / 2;
				set_camera(data, x, y);
				data->map[y][x] = '0';
			}
		}
	}
	return (!data->player->player);
}

int	only_spaces(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	valid_line(char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (!has_char(" 01NSWE\n", line[x]))
		{
			free(line);
			return (1);
		}
		if (only_spaces(line))
		{
			free(line);
			return (1);
		}
		x++;
	}
	free(line);
	return (0);
}

int	valid_chars(t_data *data)
{
	int		y;
	char	*line;

	if (data->map == NULL || data->map_height <= 0)
		return (1);
	y = 0;
	while (y < data->map_height)
	{
		line = ft_strdup(data->map[y]);
		if (line == NULL)
		{
			return (1);
		}
		if (valid_line(line))
			return (1);
		y++;
	}
	return (0);
}
