/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:33 by flverge           #+#    #+#             */
/*   Updated: 2023/10/20 16:24:35 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_flags	turbo_parsing(char *format)
{
	t_flags current_flag;

	current_flag = zero_init_struct();
	int i = 0;
	while (!is_digit(format[i]))
	{
		if (format[i] == '#')
			current_flag.hashtag = 1;
		if (format[i] == ' ')
			current_flag.space = 1;
		if (format[i] == '+')
			current_flag.plus_sign = 1;
		if (format[i] == '-')
			current_flag.minus_sign = 1;
		if (format[i] == '0')
			current_flag.zero = 1;
		i++;
	}
	if (current_flag.space == 1 && current_flag.plus_sign == 1)
	{
		current_flag.space = 0;
		current_flag.plus_sign = 0;
	}
	current_flag.width = width_or_precision(&format[i]);
	while (is_digit(format[i]))
		i++;
	if (format[i] == '.')
		current_flag.point = 1;
	if (current_flag.point = 1)
		current_flag.precision = width_or_precision(format[i]);
	while (is_digit(format[i]))
		i++;
	current_flag.placeholder = format[i];
	return (current_flag);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len_printf;
	t_flags current_flag;

	va_start(args, format);
	i = 0;
	len_printf = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			current_flag = turbo_parsing(&format[i + 1]);
			// la fonction qui trie selon le placeholder
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
