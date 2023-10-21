/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:33 by flverge           #+#    #+#             */
/*   Updated: 2023/10/21 13:29:50 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_flags	turbo_parsing(char *format)
{
	t_flags	current_flag;
	int		i;

	current_flag = zero_init_struct();
	i = 0;
	while (!ft_isdigit(format[i++]))
	{
		if (format[i] == '#')
			current_flag.hashtag++;
		if (format[i] == ' ')
			current_flag.space++;
		if (format[i] == '+')
			current_flag.plus_sign++;
		if (format[i] == '-')
			current_flag.minus_sign++;
	}
	while (format[i++] == '0')
		current_flag.zero++;
	if (format[i] != '.' && ft_isdigit(format[i]))
	{
		while (ft_isdigit(format[i]))
			i++;
	}
	while (format[i++] == '.')
		current_flag.point++;
	if (current_flag.point == 1 && ft_isdigit(format[i]))
	{
		current_flag.precision = width_or_precision(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	current_flag.placeholder = format[i];
	current_flag = cleaning_parsing(current_flag);
	return (current_flag);
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
