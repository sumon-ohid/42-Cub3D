/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_border_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:20:36 by msumon            #+#    #+#             */
/*   Updated: 2024/06/27 18:35:23 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exact_width(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\n'))
		i--;
	return (i);
}

int	exact_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	while (i > 0 && empty_line_check(map[i], 1))
		i--;
	return (i);
}

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
			return (1);
		}
		if (valid_line_borders(data, line, y))
			return (1);
		y++;
	}
	return (0);
}
