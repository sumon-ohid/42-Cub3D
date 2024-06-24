/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:48:30 by msumon            #+#    #+#             */
/*   Updated: 2024/06/24 10:53:04 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	sizeinbyte;

	sizeinbyte = nmemb * size;
	p = malloc(sizeinbyte);
	if (!p)
		return (NULL);
	if (p != NULL)
	{
		ft_bzero(p, sizeinbyte);
	}
	return (p);
}
