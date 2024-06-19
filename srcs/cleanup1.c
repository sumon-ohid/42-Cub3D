/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 10:19:24 by vsharma           #+#    #+#             */
/*   Updated: 2024/06/19 11:44:50 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	error(char *str)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("Error:\n", fd);
	ft_putstr_fd(str, fd);
	return (0);
}
int	clean_and_error(t_data *data, char *message)
{
	int	fd;

	fd = 2;
	clean_input_structure(data);
	ft_putstr_fd("Error:\n", fd);
	ft_putstr_fd(message, fd);
	return (0);
}

int	close_game(t_data *data)
{
	clean_data(data);
	exit(0);
}