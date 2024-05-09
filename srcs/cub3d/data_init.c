/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:19:42 by msumon            #+#    #+#             */
/*   Updated: 2024/05/09 13:13:50 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mlx_data_init(t_data *data)
{
	data->win_width = 1440;
	data->win_height = 1080;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (1);
	data->win = mlx_new_window(data->mlx, data->win_width, data->win_height,
			"cub3d");
	if (!data->win)
		return (error("Window creation failed.\n"));
	return (0);
}

int	img_data_init(t_img *img)
{
	img->width = IMG_W;
	img->height = IMG_H;
	return (0);
}

int	data_init(t_data *data, t_img *img, char *map_path)
{
	int		fd;
	char	*line;
	int		len;
	int		i;

	i = 0;
	len = map_line_count(map_path);
	data->map = malloc(sizeof(char *) * map_line_count(map_path) + 1);
	if (!data->map)
		return (1);
	if (mlx_data_init(data))
		return (1);
	if (img_data_init(img))
		return (1);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (i < len && line != NULL)
	{
		data->map[i] = ft_strdup(line);
		if (line[0] == 'N' && line[1] == 'O')
			data->no_texture = ft_strdup(line + 2);
		else
			data->no_texture = "././textures/floor.xpm";
		if (line[0] == 'S' && line[1] == 'O')
			data->so_texture = ft_strdup(line + 2);
		else
			data->so_texture = "././textures/greystonewall.xpm";
		if (line[0] == 'W' && line[1] == 'E')
			data->we_texture = ft_strdup(line + 2);
		else
			data->we_texture = "././textures/floor.xpm";
		if (line[0] == 'E' && line[1] == 'A')
			data->ea_texture = ft_strdup(line + 2);
		else
			data->ea_texture = "././textures/floor.xpm";
		if (line[0] == 'F')
			data->floor_color = ft_atoi(line + 1);
		else if (line[0] == 'C')
			data->ceiling_color = ft_atoi(line + 1);
		else
			i++;
		free(line);
		line = get_next_line(fd);
	}
	data->map_height = i;
	data->map_width = ft_strlen(line);
	close(fd);
	return (0);
}
