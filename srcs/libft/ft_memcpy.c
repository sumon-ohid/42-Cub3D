/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:44:31 by msumon            #+#    #+#             */
/*   Updated: 2023/09/15 12:01:58 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char		*nsrc;
	unsigned char	*ndest;
	size_t			i;

	ndest = (unsigned char *)dest;
	nsrc = (const char *)src;
	i = 0;
	if (!nsrc && !ndest)
		return (NULL);
	while (i < n)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}
