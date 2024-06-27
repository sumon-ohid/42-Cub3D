/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 13:25:04 by msumon            #+#    #+#             */
/*   Updated: 2024/06/27 15:52:08 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include "ctype.h"

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
	printf("load color\n");
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
	{
	}
	else
		return (ft_rtn(line));
	return (0);
}

char	*remove_extra_space(char *input)
{
	int		i;
	int 	j;
	char	*new_input;

	i = 0; 
	j = 0;
	new_input = malloc(ft_strlen(input) + 1);
	if (!new_input)
		return (NULL);
	while (input[i])
	{
		if (input[i] != ' ')
		{
			new_input[j] = input[i];
			j++;
		}
		else if (i > 0 && input[i - 1] != ' ')
		{
			new_input[j] = input[i];
			j++;
		}
		i++;
	}
	if (j > 0 && new_input[j - 1] == ' ')
		j--;
	new_input[j] = '\0';
	return (new_input);
}

int	load_textures_and_colors(t_data *data, int i)
{
	char	*line;
	int		j;
	int		height;

	height = height_until_map(data->map);
	while (i < height)
	{
		j = 0;
		while (data->map[i][j] == ' ')
			j++;
		if ((data->map[i][j] == '\0' || data->map[i][j] == '\n') && j != 0)
			return (1);
		if (data->map[i][j] != '1')
		{
			line = remove_extra_space(data->map[i]);
			printf("%s", line);
			if (!line)
				return (1);
			if (load_here(data, line))
				return (1);
			free(line);
		}
		i++;
	}
	return (0);
}
