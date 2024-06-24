/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:55:11 by msumon            #+#    #+#             */
/*   Updated: 2024/06/24 10:54:02 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data, int fd, char *line, int i)
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

int	initialize_map(t_data *data, char *map_path, int len)
{
	int	fd;

	data->map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!data->map)
		return (1);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (1);
	}
	return (fd);
}

int	populate_map(t_data *data, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd, data);
	if (!line)
	{
		close(fd);
		return (1);
	}
	while (line)
	{
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			free_data(data, fd, line, i);
		i++;
		free(line);
		line = get_next_line(fd, data);
		if (!line)
			break ;
	}
	data->map[i] = NULL;
	free(line);
	return (i);
}

int	finalize_map(t_data *data, int fd, int i)
{
	if (close(fd) == -1)
	{
		free_array(data->map);
		return (1);
	}
	data->map_height = i;
	data->map_width = ft_strlen(data->map[0]);
	return (0);
}

int	map_init(t_data *data, char *map_path, int len)
{
	int	fd;
	int	i;

	fd = initialize_map(data, map_path, len);
	if (fd < 0)
		return (1);
	i = populate_map(data, fd);
	if (i < 0)
		return (1);
	return (finalize_map(data, fd, i));
}
