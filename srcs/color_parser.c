/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:20:45 by msumon            #+#    #+#             */
/*   Updated: 2024/09/10 14:09:12 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*remove_extra_space(char *input, int i, int j)
{
	char	*new_input;

	new_input = malloc(ft_strlen(input) + 1);
	// if (!new_input)
	// 	return (NULL);
	while (input[i])
	{
		if (input[i] == '\t')
			return (free(new_input), NULL);
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
	if (is_empty(rgb[0]) || is_empty(rgb[1]) || is_empty(rgb[2]))
	{
		error("Invalid color\n");
		return (-1);
	}
	if (r == -1 || g == -1 || b == -1)
	{
		error("Invalid color\n");
		return (-1);
	}
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		error("Invalid color\n");
		return (-1);
	}
	return ((r << 16) + (g << 8) + b);
}

int	count_commas(char *line)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	parse_color(char *line, int i)
{
	char	**rgb;
	int		ret;

	ret = 0;
	if (count_commas(line) != 2)
		return (-1);
	rgb = ft_split(line, ',', 0, 0);
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
	{
		free_array(rgb);
		return (-1);
	}
	while (rgb[i])
		i++;
	if (i != 3)
	{
		error("Invalid Color.\n");
		free_array(rgb);
		return (-1);
	}
	ret = validate_values(rgb);
	if (ret == -1)
		return (free_array(rgb), -1);
	free_array(rgb);
	return (ret);
}
