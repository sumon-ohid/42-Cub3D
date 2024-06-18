/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsharma <vsharma@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:19:42 by msumon            #+#    #+#             */
/*   Updated: 2024/06/18 11:40:24 by vsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	allocate_textures(t_data *data)
{
	data->img = (t_img *)malloc(sizeof(t_img));
	if (!data->img)
		return (1);
	data->img->img_ptr = NULL;
	data->ea_img = (t_img *)malloc(sizeof(t_img));
	if (!data->ea_img)
		return (1);
	data->ea_img->img_ptr = NULL;
	data->no_img = (t_img *)malloc(sizeof(t_img));
	if (!data->no_img)
		return (1);
	data->no_img->img_ptr = NULL;
	data->so_img = (t_img *)malloc(sizeof(t_img));
	if (!data->so_img)
		return (1);
	data->so_img->img_ptr = NULL;
	data->we_img = (t_img *)malloc(sizeof(t_img));
	if (!data->we_img)
		return (1);
	data->we_img->img_ptr = NULL;
	return (0);
}

int	map_line_count(char *map)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!line)
		return (0);
	while (line > 0)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	//close(fd);
	return (i);
}

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
	line = get_next_line(fd); // protect
	if (!line)
	{
		close(fd);
		return (1);
	}
	while (line)
	{
		data->map[i] = ft_strdup(line);
		if (data->map[i] == NULL)
			return (1);
		if (!data->map[i])
		{
			free(line);
			close(fd);
			return (1);
		}
		i++;
		free(line);
		line = get_next_line(fd); // protect
		if (!line)
		{
			return (1);
			break ;
		}
	}
	data->map[i] = NULL;
	free(line);
	//close(fd);
	data->map_height = i;
	data->map_width = ft_strlen(data->map[0]);
	return (0);
}

int	map_extention(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (len < 4 || ft_strncmp(map_path + len - 4, ".cub", 4))
		return (1);
	return (0);
}

int	data_init(t_data *data, char *map_path)
{
	int	map_len;

	if (map_extention(map_path))
	{
		error("Invalid map file.\n");
		exit (EXIT_FAILURE);
	}
	map_len = map_line_count(map_path);
	if (map_len == 0)
	{
		error("Map file is empty.\n");
		exit (EXIT_FAILURE);
	}
	data->img = NULL;
	data->player = ft_calloc(1, sizeof(t_player));
	if (data->player == NULL)
	{
		free(data->player);
		error("Player init fails.\n");
		return(1);
	}
	data->map = NULL;
	data->mlx = NULL;
	data->win = NULL;
	data->no_texture = NULL;
	data->so_texture = NULL;
	data->we_texture = NULL;
	data->ea_texture = NULL;
	data->ea_img = NULL;
	data->no_img = NULL;
	data->so_img = NULL;
	data->we_img = NULL;
	data->floor_color = 0;
	data->ceiling_color = 0;
	data->map_path = map_path;
	data->map_width = 0;
	data->map_height = 0;
	data->ray_num = 0;
	data->ray_angle = 0;
	data->coordinate_y = 0.0;
	if (map_init(data, map_path, map_len))
	{
		//clean_data(data);
		return (1);
	}
	return (0);
}
