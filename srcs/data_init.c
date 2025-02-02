/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:19:42 by msumon            #+#    #+#             */
/*   Updated: 2024/06/24 11:54:28 by msumon           ###   ########.fr       */
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

int	map_line_count(char *map, t_data *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd, data);
	if (!line)
		return (close(fd), 0);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd, data);
		if (!line && data->gnl_failed)
			break ;
	}
	free(line);
	if (close(fd) == -1)
		return (0);
	if (data->gnl_failed)
		return (0);
	return (i);
}

int	map_extention(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (len < 4 || ft_strncmp(map_path + len - 4, ".cub", 4))
		return (1);
	return (0);
}

void	data_struct(t_data *data, char *map_path)
{
	data->img = NULL;
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
}

int	data_init(t_data *data, char *map_path)
{
	int	map_len;

	data->gnl_failed = false;
	if (map_extention(map_path))
	{
		error("Invalid map file.\n");
		exit(EXIT_FAILURE);
	}
	map_len = map_line_count(map_path, data);
	if (map_len == 0 || data->gnl_failed == true)
	{
		error("Map file is empty.\n");
		return (1);
	}
	data_struct(data, map_path);
	if (map_init(data, map_path, map_len))
		return (1);
	data->player = ft_calloc(1, sizeof(t_player));
	if (data->player == NULL)
	{
		free_array(data->map);
		error("Player init fails.\n");
		return (1);
	}
	return (0);
}
