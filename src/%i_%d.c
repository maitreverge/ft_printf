/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %i_%d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:56:30 by flverge           #+#    #+#             */
/*   Updated: 2023/10/26 13:19:20 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_plus_or_space(int nb, t_flags flags)
{
	int	plus_sign;
	int	space_sign;

	plus_sign = 0;
	space_sign = 0;

	if (flags.plus_sign && nb > 0 && !flags.space)
	{
		plus_sign++;
		ft_putchar('+');
	}
	else if (flags.space && !flags.plus_sign)
	{
		space_sign++;
		ft_putchar(' ');
	}
	return (plus_sign + space_sign);
}

int	no_width_int(int nb, int len_nb, t_flags flags)
{
	int	space_plus_flag;
	int	precision;

	precision = flags.precision - len_nb;
	space_plus_flag = print_plus_or_space(nb, flags);
	if (!flags.precision)
	{
		ft_putnbr(nb);
		flags.lenght_print = len_nb;
	}
	else
	{
		if (precision)
			print_zero(precision);
		ft_putnbr(nb);
		if (precision < 0)
			precision = 0;
		flags.lenght_print = len_nb + precision;
	}
	return (space_plus_flag + flags.lenght_print);
}

int	yes_precision(int nb, int len_nb, t_flags flags)
{
	if (!flags.width)
	{
		flags.lenght_print = no_width_int(nb, len_nb, flags)
	}
	else
	{
		
	}
	return (flags.lenght_print);
}

int	print_i_and_d(int nb, t_flags flags)
{
	int	len_nb;

	len_nb = int_len(nb);
	if (flags.point)
	{
		flags.lenght_print = yes_precision(nb, len_nb, flags);
	}
	return (flags.lenght_print);
}

/*

int	ft_print_int(int nb)
{
	ft_putnbr(nb);
	if (nb < 0)
		return (ft_intlen(nb) + 1);
	return (ft_intlen(nb));
}
*/

/*
! ETAPE 1 : Determiner la precision

*/