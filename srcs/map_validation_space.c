/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:37:05 by msumon            #+#    #+#             */
/*   Updated: 2024/07/01 17:07:46 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_middle(t_data *data, size_t x, int y)
{
	size_t	above_len;
	size_t	below_len;

	above_len = ft_strlen(data->map[y - 1]) - 1;
	below_len = ft_strlen(data->map[y + 1]) - 1;
	if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != ' ')
		return (1);
	if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != ' ')
		return (1);
	if ((ft_strlen(data->map[y]) <= above_len)
		&& (ft_strlen(data->map[y]) <= below_len))
	{
		if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ')
			return (1);
		if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
			return (1);
	}
	if ((x > above_len) && x <= below_len)
	{
		if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
			return (1);
	}
	if ((x >= above_len) && x >= below_len)
		return (0);
	return (0);
}

int	space_checker(t_data *data, size_t x, int y)
{
	size_t	width;
	size_t	above_len;
	size_t	below_len;

	above_len = ft_strlen(data->map[y - 1]) - 1;
	below_len = ft_strlen(data->map[y + 1]) - 1;
	width = ft_strlen(data->map[y]);
	if (y == 0 && data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
		return (1);
	else if (y == data->map_height - 1 && data->map[y - 1][x] != '1'
		&& data->map[y - 1][x] != ' ')
		return (1);
	else if (y > 0 && y < data->map_height - 1 && x < width - 1 && x > 0)
	{
		if ((x < above_len) && x > below_len)
		{
			if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ')
				return (1);
		}
		if (check_middle(data, x, y))
			return (1);
	}
	return (0);
}
