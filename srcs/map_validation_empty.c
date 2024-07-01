/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_empty.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:46:12 by msumon            #+#    #+#             */
/*   Updated: 2024/07/01 15:52:00 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	check_edge_rows(t_data *data, int x, int y)
// {
// 	if (y == 0 && x < (int)ft_strlen(data->map[y + 1])
// 		&& (data->map[y + 1][x] == '\0' || data->map[y + 1][x] == '\n'))
// 		return (1);
// 	if (y == data->map_height - 1 && x < (int)ft_strlen(data->map[y - 1])
// 		&& (data->map[y - 1][x] == '\0' || data->map[y - 1][x] == '\n'))
// 		return (1);
// 	return (0);
// }

int	check_middle_rows(t_data *data, int x, int y)
{
	int	len_current;
	int	len_above;
	int	len_below;
	int	shorter_length;

	len_current = ft_strlen(data->map[y]);
	len_above = ft_strlen(data->map[y - 1]);
	len_below = ft_strlen(data->map[y + 1]);
	if (len_above < len_below)
		shorter_length = len_above;
	else
		shorter_length = len_below;
	if (x < shorter_length && (data->map[y - 1][x] == ' ' || data->map[y
			- 1][x] == '\0' || data->map[y - 1][x] == '\n' || data->map[y
			+ 1][x] == ' ' || data->map[y + 1][x] == '\0' || data->map[y
			+ 1][x] == '\n'))
		return (1);
	if (len_current > shorter_length && x >= shorter_length
		&& data->map[y][x] == '0')
		return (1);
	return (0);
}

int	empty_checker(t_data *data, int x, int y)
{
	if (y != 0 && y != data->map_height - 1)
	{
		if (check_middle_rows(data, x, y))
			return (1);
	}
	return (0);
}
