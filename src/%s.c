/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %s.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:36:59 by flverge           #+#    #+#             */
/*   Updated: 2023/10/23 13:14:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	no_width(char *str, t_flags flags)
{
	ft_putstr(str);
	return (ft_strlen(str));
}

static int	yes_width(char *str, t_flags flags)
{
	if (flags.minus_sign)
	{
		ft_putstr(str);
		print_width_space(flags.width - ft_strlen(str));
	}
	else
	{
		print_width_space(flags.width - ft_strlen(str));
		ft_putstr(str);
	}
	return (6 + pos_width(flags.width, ft_strlen(str)));
}

static int	empty_string(char *nul_str, t_flags flags)
{
	if (flags.point && flags.precision < 6)
	{
		if (flags.width)
		{
			print_width_space(flags.width);
			flags.lenght_print = flags.width;
		}
	}
	if (flags.point && flags.precision >= 6)
	{
		if (!flags.width)
			flags.lenght_print = no_width(nul_str, flags);
		else
			flags.lenght_print = yes_width(nul_str, flags);
	}
	if (!flags.point)
	{
		if (!flags.width)
			flags.lenght_print = no_width(nul_str, flags);
		else
			flags.lenght_print = yes_width(nul_str, flags);
	}
	return (flags.lenght_print);
}


int	print_string(char *str, t_flags flags)
{
	int	len_str;

	if (!str)
		return (empty_string("(null)", flags));
	if (flags.point && (flags.precision < ft_strlen(str)))
		str[flags.precision] = '\0';
	len_str = ft_strlen(str);
	if (!flags.width)
		flags.lenght_print = no_width(str, flags);
	else
		flags.lenght_print = yes_width(str, flags);
	return (flags.lenght_print);
}
