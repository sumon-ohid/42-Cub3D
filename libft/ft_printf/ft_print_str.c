/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:41:08 by msumon            #+#    #+#             */
/*   Updated: 2023/10/06 08:39:42 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		return (print_str("(null)"));
	}
	else
	{
		while (*str != '\0')
		{
			print_char(*str);
			count++;
			str++;
		}
	}
	return (count);
}
