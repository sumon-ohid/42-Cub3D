/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:55:11 by msumon            #+#    #+#             */
/*   Updated: 2024/06/19 12:18:35 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_init(t_data *data, char *map_path, int len)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	data->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!data->map)
		return (1);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (1);
	}
	while (line)
	{
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
		{
			while (i >= 0)
			{
				free(data->map[i]);
				i--;
			}
			free(data->map);
			free(line);
			close(fd);
			exit(1);
		}
		i++;
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
	}
	data->map[i] = NULL;
	free(line);
	if (close(fd) == -1)
	{
		free_array(data->map);
		return (1);
	}
	data->map_height = i;
	data->map_width = ft_strlen(data->map[0]);
	return (0);
} 