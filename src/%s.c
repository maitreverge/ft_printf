/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %s.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:36:59 by flverge           #+#    #+#             */
/*   Updated: 2023/10/23 12:42:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	no_width(char *nul_str, t_flags flags)
{
	ft_putstr(nul_str);
	return (ft_strlen(nul_str));
}

static int	yes_width(char *nul_str, t_flags flags)
{
	if (flags.minus_sign)
	{
		ft_putstr(nul_str);
		print_width_space(flags.width - 6);
	}
	else
	{
		print_width_space(flags.width - 6);
		ft_putstr(nul_str);
	}
	return (6 + pos_width(flags.width, 6));
}

static int	empty_string(char *nul_str, t_flags flags)
{
	if (flags.point)
	{
		if (flags.precision < 6)
		{
			if (flags.width)
			{
				print_width_space(flags.width);
				flags.lenght_print = flags.width;
			}
		}
		else
		{
			flags.lenght_print = yes_width(nul_str, flags);
			if (!flags.width)
				flags.lenght_print = no_width(nul_str, flags);
		}
	}
	else
	{
		flags.lenght_print = yes_width(nul_str, flags);
		if (!flags.width)
			flags.lenght_print = no_width(nul_str, flags);
	}
	return (flags.lenght_print);
}


int	print_string(char *str, t_flags flags)
{
	if (!str)
		return (empty_string("(null)", flags));
	
}

/*
* IMPORTANT :
! Commencer par la precision, car elle influence la width


*/
