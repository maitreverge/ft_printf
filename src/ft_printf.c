/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:33 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 10:42:34 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	check_next_char(char next_char, va_list args)
{
	int	result;

	result = 0;
	if (next_char == 'c')
		result = ft_print_char(va_arg(args, int));
	else if (next_char == '%')
		result = ft_print_char('%');
	else if (next_char == 's')
		result = ft_print_string(va_arg(args, char *));
	else if (next_char == 'p')
		result = ft_print_adress(va_arg(args, unsigned long long));
	else if (next_char == 'u')
		result = ft_print_unsigned_int(va_arg(args, unsigned int));
	else if (next_char == 'i' || next_char == 'd')
		result = ft_print_int(va_arg(args, int));
	else if (next_char == 'x' || next_char == 'X')
		result = ft_print_hexa(va_arg(args, unsigned int), next_char);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len_printf;

	va_start(args, format);
	i = 0;
	len_printf = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len_printf += check_next_char(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			len_printf++;
		}
		i++;
	}
	va_end(args);
	return (len_printf);
}
