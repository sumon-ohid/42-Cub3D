/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_empty.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:37:05 by msumon            #+#    #+#             */
/*   Updated: 2024/06/29 15:39:04 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	edge_case_checker(t_data *data, size_t x, int y)
{
	if (y == 0 && data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
		return (1);
	if (y == data->map_height - 1 && data->map[y - 1][x] != '1' && data->map[y
		- 1][x] != ' ')
		return (1);
	return (0);
}

int	check_adjacent_cells(t_data *data, size_t x, int y)
{
	if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != ' ')
		return (1);
	if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != ' ')
		return (1);
	if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != ' ')
		return (1);
	if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
		return (1);
	return (0);
}

int	general_case_checker(t_data *data, size_t x, int y)
{
	size_t	width;

	width = exact_width(data->map[y]);
	if (y > 0 && y < data->map_height - 1 && x < width - 1 && x > 0)
	{
		data->map[y][x] = '1';
		if (check_adjacent_cells(data, x, y))
			return (1);
		if (x > ft_strlen(data->map[y - 1]) && x <= ft_strlen(data->map[y + 1])
			&& data->map[y + 1][x] != '1' && data->map[y + 1][x] != ' ')
			return (1);
		if (x < ft_strlen(data->map[y - 1]) && x > ft_strlen(data->map[y + 1])
			&& data->map[y - 1][x] != '1' && data->map[y + 1][x] != ' ')
			return (1);
	}
	return (0);
}

int	space_checker(t_data *data, size_t x, int y)
{
	if (edge_case_checker(data, x, y))
		return (1);
	if (general_case_checker(data, x, y))
		return (1);
	return (0);
}
