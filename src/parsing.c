/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:31:47 by flverge           #+#    #+#             */
/*   Updated: 2023/10/25 10:39:44 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	zero_init_struct(void)
{
	t_flags	f;

	f.placeholder = '\0';
	f.hashtag = 0;
	f.plus_sign = 0;
	f.space = 0;
	f.minus_sign = 0;
	f.zero = 0;
	f.width = 0;
	f.point = 0;
	f.precision = 0;
	f.lenght_print = 0;
	return (f);
}

t_flags	cleaning_parsing(t_flags f)
{
	if (f.plus_sign >= 1 && f.space >= 1)
	{
		f.plus_sign = 0;
		f.space = 0;
	}
	if (f.hashtag > 1)
		f.hashtag = 1;
	if (f.plus_sign > 1)
		f.plus_sign = 1;
	if (f.space > 1)
		f.space = 1;
	if (f.minus_sign > 1)
		f.minus_sign = 1;
	if (f.zero > 1)
		f.zero = 1;
	if (f.point > 1)
		f.point = 1;
	return (f);
}

t_flags	first_part_parsing(const char *format, int *i)
{
	t_flags	current_flag;

	current_flag = zero_init_struct();
	while (!ft_isdigit(format[*i]))
	{
		if (format[*i] == '#')
			current_flag.hashtag++;
		else if (format[*i] == ' ')
			current_flag.space++;
		else if (format[*i] == '+')
			current_flag.plus_sign++;
		else if (format[*i] == '-')
			current_flag.minus_sign++;
		(*i)++;
	}
	return (current_flag);
}

int	check_placeholder(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

t_flags	turbo_parsing(const char *format)
{
	t_flags	current_flag;
	int		i;

	current_flag = zero_init_struct();
	i = 0;
	if (check_placeholder(format[i]) == 1)
	{
		current_flag.placeholder = format[i];
		return (current_flag);
	}
	if (format[i] != '.')
		current_flag = first_part_parsing(&format[i], &i);
	while (format[i] == '0')
	{
		current_flag.zero++;
		i++;
	}
	if (format[i] != '.' && ft_isdigit(format[i]))
	{
		current_flag.width = width_or_precision(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	while (format[i] == '.')
	{
		current_flag.point++;
		i++;
	}
	if (current_flag.point && ft_isdigit(format[i]))
	{
		current_flag.precision = width_or_precision(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	current_flag.placeholder = format[i];
	current_flag = cleaning_parsing(current_flag);
	return (current_flag);
}
