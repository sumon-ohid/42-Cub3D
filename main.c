/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon < msumon@student.42vienna.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 10:53:23 by msumon            #+#    #+#             */
/*   Updated: 2024/05/08 21:25:01 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	error(char *str)
{
	int	fd;

	fd = 2;
	ft_putstr_fd("Error.\n", fd);
	ft_putstr_fd(str, fd);
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (error("Invalid number of arguments\n"));
	if (map_validation(av[1], 0))
		return (error("Invalid map.\n"));
	return (0);
}
