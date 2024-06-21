/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:24:16 by msumon            #+#    #+#             */
/*   Updated: 2024/06/21 15:49:24 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_i(char **map, int i)
{
	int j;

	j = 0;
	while (j <= i)
	{
		free(map[j]);
		j++;
	}
	free(map);
}

char	**initialize_new_map(t_data *data)
{
	char	**new_map;

	new_map = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!new_map)
	{
		return (NULL);
	}
	return (new_map);
}

int	process_map_lines(char **map, int *i)
{
	char	*line;

	while (map[*i])
	{
		line = remove_space(map[*i]);
		if (!line)
		{
			return (1);
		}
		if (line[0] == '1')
		{
			free(line);
			break ;
		}
		free(line);
		(*i)++;
	}
	return (0);
}

int	copy_map_lines(char **map, char **new_map, int *i, int *j)
{
	while (map[*i])
	{
		new_map[*j] = ft_strdup(map[*i]);
		if (!new_map[*j])
		{
			free_i(new_map, *i);
			return (1);
		}
		(*i)++;
		(*j)++;
	}
	return (0);
}

int	map_without_textures(char **map, t_data *data)
{
	int		i;
	int		j;
	char	**new_map;

	i = 0;
	j = 0;
	new_map = initialize_new_map(data);
	if (!new_map)
		return (1);
	if (process_map_lines(map, &i))
	{
		free(new_map);
		return (1);
	}
	if (copy_map_lines(map, new_map, &i, &j))
	{
		return (1);
	}
	new_map[j] = NULL;
	free_array(data->map);
	data->map = new_map;
	return (0);
}
