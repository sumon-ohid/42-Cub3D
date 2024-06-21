/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:20:45 by msumon            #+#    #+#             */
/*   Updated: 2024/06/21 13:01:50 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	texture_end_xpm(char *line)
{
	int	i;
	int	len;

	len = ft_strlen(line);
	i = len - 5;
	if (ft_strncmp(line + i, ".xpm", 4))
		return (1);
	return (0);
}

char	*copy_until_newline(char *line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	new_line = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!new_line)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		new_line[j] = line[i];
		i++;
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

int	validate_values(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		error("Invalid color\n");
		return (0);
	}
	return ((r << 16) + (g << 8) + b);
}

int	parse_color(char *line, int i)
{
	char	**rgb;
	int		ret;

	ret = 0;
	rgb = ft_split(line, ',', 0, 0);
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_array(rgb);
		return (0);
	}
	while (rgb[i])
		i++;
	if (i != 3)
	{
		error("Invalid Color.\n");
		free_array(rgb);
		return (0);
	}
	ret = validate_values(rgb);
	free_array(rgb);
	return (ret);
}
