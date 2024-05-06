/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:10:44 by msumon            #+#    #+#             */
/*   Updated: 2023/09/15 11:32:30 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	filler;

	i = 0;
	string = s;
	filler = (unsigned char)c;
	while (i < n)
	{
		string[i] = filler;
		i++;
	}
	return (s);
}
