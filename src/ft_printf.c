/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:33 by flverge           #+#    #+#             */
/*   Updated: 2023/10/23 11:33:12 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	placeholder_behaviour(t_flags flags, va_list args)
{
	int	result;

	result = 0;
	if (flags.placeholder == '%')
		result = print_char('%', flags);
	else if (flags.placeholder == 'c')
		result = print_char(va_arg(args, char), flags);
	else if (flags.placeholder == 's')
		result = print_string(va_arg(args, char *), flags);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len_printf;
	t_flags	current_flag;

	va_start(args, format);
	i = 0;
	len_printf = 0;
	while (format[i++])
	{
		if (format[i] == '%')
		{
			current_flag = turbo_parsing(&format[i + 1]);
			len_printf += placeholder_behaviour(current_flag, args);
			i++;
		}
		else
		{
			ft_putchar(format[i]);
			len_printf++;
		}
	}
	va_end(args);
	return (len_printf);
}
