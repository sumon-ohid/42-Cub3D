/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:37:05 by msumon            #+#    #+#             */
/*   Updated: 2024/07/01 12:39:20 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_middle(t_data *data, size_t x, int y)
{
	data->map[y][x] = '1';
	if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != ' ')
		return (1);
	if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != ' ')
		return (1);
	if (ft_strlen(data->map[y]) <= ft_strlen(data->map[y - 1])
		&& ft_strlen(data->map[y]) <= ft_strlen(data->map[y + 1]))
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
	return (0);
}

int	space_checker(t_data *data, size_t x, int y)
{
	size_t	width;

	width = ft_strlen(data->map[y]);
	if (y == 0 && data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
		return (1);
	else if (y == data->map_height - 1 && data->map[y - 1][x] != '1'
		&& data->map[y - 1][x] != ' ')
		return (1);
	else if (y > 0 && y < data->map_height - 1 && x < width - 1 && x > 0)
	{
		if (check_middle(data, x, y))
			return (1);
	}
	return (0);
}
