/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:25:04 by msumon            #+#    #+#             */
/*   Updated: 2024/06/19 15:33:14 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_rtn(char *line)
{
	if (line)
		free(line);
	return (1);
}

int	load_texture(char *line, char **texture)
{
	if (*texture)
		return (ft_rtn(line));
	*texture = copy_until_newline(line + 2);
	if (!*texture)
		return (ft_rtn(line));
	return (0);
}

int	load_color(char *line, int *color)
{
	if (*color)
		return (ft_rtn(line));
	*color = parse_color(line + 1, 0);
	if (!*color)
		return (ft_rtn(line));
	return (0);
}

int	load_here(t_data *data, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (load_texture(line, &data->no_texture));
	else if (line[0] == 'S' && line[1] == 'O')
		return (load_texture(line, &data->so_texture));
	else if (line[0] == 'W' && line[1] == 'E')
		return (load_texture(line, &data->we_texture));
	else if (line[0] == 'E' && line[1] == 'A')
		return (load_texture(line, &data->ea_texture));
	else if (line[0] == 'F')
		return (load_color(line, &data->floor_color));
	else if (line[0] == 'C')
		return (load_color(line, &data->ceiling_color));
	else if (line[0] == ' ' || line[0] == '\n')
		printf(" ");
	else
		return (ft_rtn(line));
	return (0);
}

int	load_textures_and_colors(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (data->map[i] && data->map[i][0] != '1')
	{
		line = remove_space(data->map[i]);
		if (!line)
			return (1);
		if (load_here(data, line))
			return (1);
		free(line);
		i++;
	}
	return (0);
}

/*int	load_textures_and_colors(t_data *data)
{
	char	*line;
	int		i;

	i = 0;
	while (data->map[i] && data->map[i][0] != '1')
	{
		line = remove_space(data->map[i]);
		if (!line)
			return (1);
		if (line[0] == 'N' && line[1] == 'O')
		{
			if (data->no_texture)
				return (ft_rtn(line));
			data->no_texture = copy_until_newline(line + 2);
			if (!data->no_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'S' && line[1] == 'O')
		{
			if (data->so_texture)
				return (ft_rtn(line));
			data->so_texture = copy_until_newline(line + 2);
			if (!data->so_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'W' && line[1] == 'E')
		{
			if (data->we_texture)
				return (ft_rtn(line));
			data->we_texture = copy_until_newline(line + 2);
			if (!data->we_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'E' && line[1] == 'A')
		{
			if (data->ea_texture)
				return (ft_rtn(line));
			data->ea_texture = copy_until_newline(line + 2);
			if (!data->ea_texture)
				return (ft_rtn(line));
		}
		else if (line[0] == 'F')
		{
			if (data->floor_color)
				return (ft_rtn(line));
			data->floor_color = parse_color(line + 1, 0);
			if (!data->floor_color)
				return (ft_rtn(line));
		}
		else if (line[0] == 'C')
		{
			if (data->ceiling_color)
				return (ft_rtn(line));
			data->ceiling_color = parse_color(line + 1, 0);
			if (!data->ceiling_color)
				return (ft_rtn(line));
		}
		else if (line[0] == ' ' || line[0] == '\n')
			printf(" ");
		else
			return(ft_rtn(line));
		free(line);
		i++;
	}
	return (0);
}*/