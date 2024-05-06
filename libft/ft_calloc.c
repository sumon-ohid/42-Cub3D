/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 14:48:30 by msumon            #+#    #+#             */
/*   Updated: 2023/11/24 14:46:04 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
