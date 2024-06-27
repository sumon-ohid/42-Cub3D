/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:12:40 by msumon            #+#    #+#             */
/*   Updated: 2024/06/27 18:35:02 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int	empty_line_check(char *line, int flag)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i] != '\0')
	{
		if (flag == 0)
		{
			if (line[i] != '\n')
				return (0);
		}
		else
		{
			if (line[i] != ' ' && line[i] != '\n')
				return (0);
		}
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
		if (empty_line_check(line, 1))
		{
			free(line);
			return (1);
		}
		if (!has_char(" 01NSWE\n", line[x]))
		{
			free(line);
			return (1);
		}
		x++;
	}
	free(line);
	return (0);
}

int	has_spaces_in_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	valid_chars(t_data *data)
{
	int		y;
	char	*line;
	int		height;

	height = exact_map_height(data->map);
	if (data->map == NULL || data->map_height <= 0)
		return (1);
	y = -1;
	while (++y < height - 1)
	{
		line = ft_strdup(data->map[y]);
		if (line == NULL)
			return (1);
		if (valid_line(line))
			return (1);
	}
	y = 0;
	while (data->map[y])
		y++;
	while (--y > height)
	{
		if (has_spaces_in_line(data->map[y]))
			return (1);
	}
	return (0);
}
