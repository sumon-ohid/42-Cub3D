/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:41:54 by msumon            #+#    #+#             */
/*   Updated: 2023/10/10 11:26:14 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_digit(long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0)
	{
		print_char('-');
		count += (print_digit(-n, base) + 1);
		return (count);
	}
	else if (n < base)
	{
		count += (print_char(symbols[n]));
		return (count);
	}
	else
	{
		count += print_digit(n / base, base);
		count += (count + print_digit(n % base, base));
		return (count);
	}
}
