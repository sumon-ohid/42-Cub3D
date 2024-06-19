/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:20:36 by msumon            #+#    #+#             */
/*   Updated: 2024/06/19 14:25:10 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	valid_line_borders(t_data *data, char *line, int y)
{
	int	x;
	int	width;

	x = 0;
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
		else if (line[x] == ' ' && (line[x - 1] != '1' || line[x + 1] != '1'))
		{
			free(line);
			return (1);
		}
		x++;
	}
	free(line);
	return (0);
}

int	valid_borders(t_data *data)
{
	int		y;
	char	*line;

	y = 0;
	while (y < data->map_height)
	{
		line = remove_space(data->map[y]);
		if (!line)
		{
			free(data->player);
			return (1);
		}
		if (valid_line_borders(data, line, y))
			return (1);
		y++;
	}
	return (0);
}

/*static int	valid_borders(t_data *data)
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
		if (!line)
		{
			free(data->player);
			return (1);
		}
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
} */
