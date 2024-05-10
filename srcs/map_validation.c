// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   map_validation.c                                   :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/05/08 20:28:31 by msumon            #+#    #+#             */
// /*   Updated: 2024/05/10 21:46:26 by msumon           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cub3d.h"

// int	map_line_count(char *map)
// {
// 	int		fd;
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	fd = open(map, O_RDONLY);
// 	if (fd < 0)
// 		return (0);
// 	line = get_next_line(fd);
// 	while (line > 0)
// 	{
// 		i++;
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	free(line);
// 	close(fd);
// 	return (i);
// }

// int	free_array(char **array)
// {
// 	int	i;

// 	i = 0;
// 	while (array[i])
// 	{
// 		free(array[i]);
// 		i++;
// 	}
// 	free(array);
// 	return (0);
// }

// int	just_one_and_space(char *line)
// {
// 	int	i;

// 	i = 0;
// 	while (line[i] != '\0' && line[i] != '\n')
// 	{
// 		if (line[i] == '1')
// 			i++;
// 		else if (line[i] == ' ')
// 			i++;
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

// int	check_map(char **map, int i, int j, int player_count)
// {
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
// 				|| map[i][j] == 'E')
// 				player_count++;
// 			if (map[i][j] == '0' || map[i][j] == '1' || map[i][j] == ' '
// 				|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E'
// 				|| map[i][j] == 'N' || map[i][j] == '\n')
// 				j++;
// 			else
// 				return (1);
// 		}
// 		// need to implement if the map is surrounded by walls
// 		i++;
// 	}
// 	if (player_count != 1)
// 		return (1);
// 	if (just_one_and_space(map[0]) || just_one_and_space(map[i - 1]))
// 		return (1);
// 	free_array(map);
// 	return (0);
// }

// int	map_validation(char *map, int i)
// {
// 	int		fd;
// 	char	*line;
// 	char	**map_array;

// 	if (map_line_count(map) == 0)
// 		return (1);
// 	i = map_line_count(map);
// 	map_array = (char **)malloc(sizeof(char *) * (i + 1));
// 	if (!map_array)
// 		return (0);
// 	fd = open(map, O_RDONLY);
// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line > 0)
// 	{
// 		map_array[i] = ft_strdup(line);
// 		free(line);
// 		line = get_next_line(fd);
// 		i++;
// 	}
// 	map_array[i] = NULL;
// 	close(fd);
// 	if (check_map(map_array, 0, 0, 0))
// 		return (1);
// 	return (0);
// }


#include "../includes/cub3d.h"

int	ft_contains(const char *set, char c)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	find_player(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map_height)
	{
		x = -1;
		while (++x < data->map_width)
		{
			if (ft_contains("NSWE", data->map[y][x]))
			{
				if (data->player.player)
					return (1);
				data->player.player = data->map[y][x];
				data->player.x = x * IMAGE_SIZE + IMAGE_SIZE / 2;
				data->player.y = y * IMAGE_SIZE + IMAGE_SIZE / 2;
				set_camera(data, x, y);
				data->map[y][x] = '0';
			}
		}
	}
	return (!data->player.player);
}

static int	check_borders(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_height)
	{
		if (data->map[i][0] == '0' || data->map[i][data->map_width - 1] == '0')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->map_width)
	{
		if (data->map[0][i] == '0' || data->map[data->map_height - 1][i] == '0')
			return (1);
		i++;
	}
	return (0);
}

static int	validate_chars(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (!ft_contains("10 NSWE", data->map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_walls(t_data *data)
{
	int	x;
	int	y;

	y = 1;
	while (y < data->map_height - 1)
	{
		x = 1;
		while (x < data->map_width - 1)
		{
			if (ft_contains("NSWE0", data->map[y][x]))
			{
				if (data->map[y][x + 1] == ' ' || data->map[y][x - 1] == ' '
					|| data->map[y + 1][x] == ' ' || data->map[y - 1][x] == ' ')
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	is_valid_map(t_data *data)
{
	if (find_player(data))
		return (0);
	if (validate_chars(data))
		return (0);
	if (check_borders(data))
		return (0);
	if (check_walls(data))
		return (0);
	return (1);
}
