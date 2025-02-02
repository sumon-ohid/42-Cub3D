/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:57:24 by msumon            #+#    #+#             */
/*   Updated: 2024/06/24 11:54:40 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	if (s[len] == '\n')
		return (len + 1);
	return (len);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)
				+ 1));
	if (!(str))
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1 && s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
	{
		str[j++] = s2[i];
		if (s2[i++] == '\n')
			break ;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

size_t	clean_line(char *buffer)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = 0;
	j = 0;
	result = 0;
	while (buffer[i])
	{
		if (result)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			result = 1;
		buffer[i] = 0;
		i++;
	}
	return (result);
}

int	ft_read(int fd, char *buffer, t_data *data)
{
	int		read_bytes;

	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		data->gnl_failed = true;
		return (-1);
	}
	buffer[read_bytes] = '\0';
	return (read_bytes);
}

char	*get_next_line(int fd, t_data *data)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	(void)data;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (buffer[0] || ft_read(fd, buffer, data) > 0)
	{
		line = ft_strjoin_gnl(line, buffer);
		if (!line)
		{
			free(line);
			data->gnl_failed = true;
			return (NULL);
		}
		if (clean_line(buffer) == 1)
			break ;
		if (ft_read(fd, buffer, data) < 0)
		{
			free(line);
			return (NULL);
		}
	}
	return (line);
}
