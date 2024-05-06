/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msumon <msumon@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 09:03:17 by msumon            #+#    #+#             */
/*   Updated: 2023/11/16 21:39:29 by msumon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == 'd')
		count += print_digit((long)va_arg(args, int), 10);
	else if (specifier == 'u')
		count += print_digit((long)va_arg(args, unsigned int), 10);
	else if (specifier == 'i')
		count += print_digit((long)va_arg(args, int), 10);
	else if (specifier == 'x')
		count += print_digit((long)va_arg(args, unsigned int), 16);
	else if (specifier == 'X')
		count += print_digit_cap((long)va_arg(args, unsigned int), 16);
	else if (specifier == 'p')
		count += print_pointer(va_arg(args, void *));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	va_start(args, str);
	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += print_format(str[i + 1], args);
			i++;
		}
		else
		{
			count += write(1, &str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int		count;
// 	char	*ptr;

// 	ptr = "Hello";
// 	count = ft_printf(" 1 Hello %s\n", "Sumon");
// 	ft_printf(" 1 The chars written are %d\n", count);
// 	count = ft_printf(" 2 %x\n", 468);
// 	ft_printf(" 2 The char written are %d\n", count);
// 	count = ft_printf(" 3 %X\n", 468);
// 	ft_printf(" 3 The char written are %d\n", count);
// 	count = ft_printf(" 4 Char %c %c %c\n", 'A', 'B', 'C');
// 	ft_printf(" 4 The char written are %d\n", count);
// 	count = ft_printf(" 5 Number is :%d\n", -2147483648);
// 	ft_printf(" 5 The char written are %d\n", count);
// 	count = ft_printf("Pointer address: %p\n", (void *)ptr);
// 	ft_printf("The chars written are %d\n", count);
// 	count = printf("Pointer address: %p\n", (void *)ptr);
// 	printf("The chars written are %d\n", count);
// 	return (0);
// }
