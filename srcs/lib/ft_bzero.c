/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:33:50 by msumon            #+#    #+#             */
/*   Updated: 2024/06/24 10:53:04 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t			i;

	string = s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}
