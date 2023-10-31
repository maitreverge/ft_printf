/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %X.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:55:46 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 12:42:18 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_X(unsigned int n, t_flags flags)
{
	unsigned long	nb;
	int				len_nb;
	int				hashtag;

	nb = n;
	len_nb = intlen_hexa_zero(n);
	hashtag = 0;
	if (!flags.point)
		flags.lenght_print = preci_0_X(nb, len_nb, flags, hashtag);
	else
		flags.lenght_print = preci_1_X(nb, len_nb, flags, hashtag);
	return (flags.lenght_print);
}

int	preci_0_X(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	if (!flags.width)
		flags.lenght_print = preci_0_width_0_X(nb, len_nb, flags, hashtag);
	else
		flags.lenght_print = preci_0_width_1_X(nb, len_nb, flags, hashtag);
	return (flags.lenght_print);
}

int	preci_0_width_0_X(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	hashtag = print_hashtag_up(flags, nb);
	putnbr_hexa(nb, 'X');
	return (len_nb + hashtag);
}

int	preci_0_width_1_X(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	int	real_width;

	if (flags.minus_sign)
	{
		hashtag = print_hashtag_up(flags, nb);
		putnbr_hexa(nb, 'X');
		real_width = flags.width - hashtag - len_nb;
		if (real_width > 0)
			print_width_space(real_width);
		else
			real_width = 0;
	}
	else
	{
		if (!flags.zero)
		{
			real_width = flags.width - determine_hashtag(flags, nb) - len_nb;
			if (real_width > 0)
			{
				if (flags.zero)
					print_zero(real_width);
				else
					print_width_space(real_width);
			}
			else
				real_width = 0;
			hashtag = print_hashtag_up(flags, nb);
			putnbr_hexa(nb, 'X');
		}
		else
		{
			hashtag = print_hashtag_up(flags, nb);
			real_width = flags.width - hashtag - len_nb;
			if (real_width > 0)
			{
				if (flags.zero)
					print_zero(real_width);
				else
					print_width_space(real_width);
			}
			else
				real_width = 0;
			putnbr_hexa(nb, 'X');
		}
	}
	return (len_nb + hashtag + real_width);
}

int	preci_1_X(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	if (!flags.width)
		flags.lenght_print = preci_1_width_0_X(nb, len_nb, flags, hashtag);
	else
		flags.lenght_print = preci_1_width_1_X(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_1_width_0_X(unsigned long nb, int len_nb, t_flags flags, int hashtag)
{
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb == 0 && flags.precision == 0)
		return (0);
	real_precision = flags.precision - len_prec;
	hashtag = print_hashtag_up(flags, nb);
	if (real_precision > 0)
		print_zero(real_precision);
	else
		real_precision = 0;
	putnbr_hexa(nb, 'X');
	return (len_nb + hashtag + real_precision);
}

int	preci_1_width_1_X(unsigned long nb, int len_nb, t_flags flags)
{
	int	real_width;
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	real_precision = flags.precision - len_prec;
	if (real_precision < 0)
		real_precision = 0;
	real_width = flags.width - determine_hashtag(flags, nb) - len_nb - real_precision;
	if (real_width < 0)
		real_width = 0;
	if (!flags.precision && !nb)
		return (zero_case(flags));
	if (!flags.minus_sign)
	{
		print_width_space(real_width);
		print_hashtag_up(flags, nb);
		if (real_precision > 0)
			print_zero(real_precision);
		putnbr_hexa(nb, 'X');
	}
	else
	{
		print_hashtag_up(flags, nb);
		if (real_precision > 0)
			print_zero(real_precision);
		putnbr_hexa(nb, 'X');
		print_width_space(real_width);
	}
	return (len_nb + real_width + real_precision);
}
