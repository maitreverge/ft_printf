/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:33 by flverge           #+#    #+#             */
/*   Updated: 2023/10/19 16:58:27 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	turbo_parsing(char next_char, va_list args)
{
	int	result;

	result = 0;
	

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
			len_printf += check_next_char(&format[i], args);
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
