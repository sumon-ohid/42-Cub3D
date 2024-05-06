/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:34:06 by msumon            #+#    #+#             */
/*   Updated: 2023/10/05 06:14:45 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_pointer(void *ptr)
{
	int				count;
	unsigned long	n;
	int				i;
	char			hex_digits[16];
	char			*symbols;

	count = 0;
	n = (unsigned long)ptr;
	symbols = "0123456789abcdef";
	if (n == 0)
		return (print_str("(nil)"));
	else
	{
		count += print_str("0x");
		i = 0;
		while (n > 0)
		{
			hex_digits[i++] = symbols[n % 16];
			n /= 16;
		}
		while (i-- > 0)
			count += print_char(hex_digits[i]);
	}
	return (count);
}
