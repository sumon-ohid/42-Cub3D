/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:36:10 by msumon            #+#    #+#             */
/*   Updated: 2024/05/11 10:36:12 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_contains(const char *set, char c)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	find_player(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (ft_contains("NSWE", data->map[y][x]))
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

static int	check_borders(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] == '0' || data->map[i][data->map_width - 1] == '0')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->map_width)
	{
		if (data->map[0][i] == '0' || data->map[data->map_height - 1][i] == '0')
			return (1);
		i++;
	}
	return (0);
}

static int	validate_chars(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (!ft_contains("10 NSWE", data->map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_walls(t_data *data)
{
	int	x;
	int	y;

	y = 1;
	while (y < data->map_height - 1)
	{
		x = 1;
		while (x < data->map_width - 1)
		{
			if (ft_contains("NSWE0", data->map[y][x]))
			{
				if (data->map[y][x + 1] == ' ' || data->map[y][x - 1] == ' '
					|| data->map[y + 1][x] == ' ' || data->map[y - 1][x] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_valid_map(t_data *data)
{
	if (find_player(data))
		return (0);
	if (validate_chars(data))
		return (0);
	if (check_borders(data))
		return (0);
	if (check_walls(data))
		return (0);
	return (1);
}
