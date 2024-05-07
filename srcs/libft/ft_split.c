/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 07:40:56 by sumon             #+#    #+#             */
/*   Updated: 2023/09/19 15:33:59 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **s_split, size_t x)
{
	size_t	i;

	i = 0;
	while (i < x)
	{
		free(s_split[i]);
		i++;
	}
	free(s_split);
	return (NULL);
}

static size_t	ft_counter(char const *s, char c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			x++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**s_split;
	size_t	begin;
	size_t	end;
	size_t	i;

	begin = 0;
	i = 0;
	s_split = (char **)malloc(sizeof(char *) * (ft_counter(s, c) + 1));
	if (!s || s_split == NULL)
		return (NULL);
	while (i < ft_counter(s, c))
	{
		while (s[begin] == c)
			begin++;
		end = begin;
		while (s[end] != c && s[end] != '\0')
			end++;
		s_split[i] = ft_substr(s, begin, (end - begin));
		if (!s_split[i])
			return (ft_free(s_split, i));
		begin = end;
		i++;
	}
	s_split[i] = 0;
	return (s_split);
}
