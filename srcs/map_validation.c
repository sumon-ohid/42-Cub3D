/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:36:10 by msumon            #+#    #+#             */
/*   Updated: 2024/06/12 13:13:53 by msumon           ###   ########.fr       */
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

static int	has_player(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width - 1)
		{
			if (has_char("NSWE", data->map[y][x]))
			{
				if (data->player.player)
					return (1);
				data->player.player = data->map[y][x];
				data->player.x = x * IMAGE_SIZE + IMAGE_SIZE / 2;
				data->player.y = y * IMAGE_SIZE + IMAGE_SIZE / 2;
				set_camera(data, x, y);
				data->map[y][x] = '0';
			}
		}
	}
	return (!data->player.player);
}

static int	valid_borders(t_data *data)
{
	int		x;
	int		y;
	int		width;
	char	*line;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		line = remove_space(data->map[y]);
		width = ft_strlen(line);
		while (x < width - 1)
		{
			if (y == 0 || y == data->map_height - 1 || x == 0 || x == width - 2)
			{
				if (line[x] != '1')
				{
					free(line);
					return (1);
				}
			}
			else if (line[x] == ' ' && (line[x - 1] != '1' || line[x
					+ 1] != '1'))
			{
				free(line);
				return (1);
			}
			x++;
		}
		free(line);
		y++;
	}
	return (0);
}

static int	valid_chars(t_data *data)
{
	int		x;
	int		y;
	char	*line;

	// printf("map_height: %d\n", data->map_height);
	if (data->map == NULL || data->map_height <= 0)
		return (1);
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		line = ft_strdup(data->map[y]);
		if (line == NULL)
			return (1);
		while (line[x])
		{
			if (!has_char(" 01NSWE\n", line[x]))
			{
				free(line);
				return (1);
			}
			x++;
		}
		free(line);
		y++;
	}
	return (0);
}

int	wall_checker(t_data *data, int x, int y)
{
	if (y == 0 && data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
	{
		return (1);
	}
	else if (y == data->map_height - 1 && data->map[y - 1][x] != '1'
		&& data->map[y - 1][x] != ' ')
	{
		return (1);
	}
	else if (y != 0 && y != data->map_height - 1) // need to fix this
	{
		if ((data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ')
			&& (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' '))
			return (1);
	}
	return (0);
}

int	empty_checker(t_data *data, int x, int y)
{
	if (y == 0 && data->map[y + 1][x] == '\0')
	{
		return (1);
	}
	else if (y == data->map_height - 1 && data->map[y - 1][x] == '\0')
	{
		return (1);
	}
	else if (y != 0 && y != data->map_height - 1)
	{
		if (data->map[y - 1][x] == '\0' && data->map[y + 1][x] == '\0')
			return (1);
	}
	return (0);
}

static int	valid_walls(t_data *data)
{
	int	x;
	int	y;

	if (!data || !data->map)
		return (1);
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x] != '\0' && data->map[y][x] != '\n')
		{
			if (data->map[y][x] == ' ')
			{
				if (wall_checker(data, x, y))
					return (1);
			}
			if (data->map[y][x] == '0')
			{
				if (empty_checker(data, x, y))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}


int	valid_map(t_data *data)
{
	if (has_player(data))
		return (0);
	// printf("valid_player\n");
	if (valid_chars(data))
		return (0);
	// printf("valid_chars\n");
	if (valid_borders(data))
		return (0);
	// printf("valid_borders\n");
	if (valid_walls(data))
		return (0);
	// printf("valid_walls\n");
	if (map_without_textures(data->map, data))
		return (0);
	data->map_width = ft_strlen(data->map[0]) - 1;
	data->map_height = 0;
	while (data->map[data->map_height])
		data->map_height++;
	return (1);
}
