/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %u.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:51:12 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 12:41:17 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(unsigned int n, t_flags flags)
{
	long	nb;
	int		len_nb;

	nb = n;
	len_nb = int_len_zero(n);
	if (!flags.point)
		flags.lenght_print = preci_0_u(nb, len_nb, flags);
	else
		flags.lenght_print = preci_1_u(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_0_u(long nb, int len_nb, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = preci_0_width_0_u(nb, len_nb);
	else
		flags.lenght_print = preci_0_width_1_u(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_0_width_0_u(long nb, int len_nb)
{
	ft_putnbr(nb);
	return (len_nb);
}

int	preci_0_width_1_u(long nb, int len_nb, t_flags flags)
{
	int	real_width;

	if (flags.minus_sign)
	{
		ft_putnbr(nb);
		real_width = flags.width - len_nb;
		if (real_width > 0)
			print_width_space(real_width);
		else
			real_width = 0;
	}
	else
	{
		if (!flags.zero)
		{
			real_width = flags.width - determine_plus(nb, flags) - len_nb;
			if (real_width > 0)
			{
				if (flags.zero)
					print_zero(real_width);
				else
					print_width_space(real_width);
			}
			else
				real_width = 0;
			ft_putnbr(nb);
		}
		else
		{
			real_width = flags.width - len_nb;
			if (real_width > 0)
			{
				if (flags.zero)
					print_zero(real_width);
				else
					print_width_space(real_width);
			}
			else
				real_width = 0;
			ft_putnbr(positive_nb(nb));
		}
	}
	return (len_nb + real_width);
}

int	preci_1_u(long nb, int len_nb, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = preci_1_width_0_u(nb, len_nb, flags);
	else
		flags.lenght_print = preci_1_width_1_u(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_1_width_0_u(long nb, int len_nb, t_flags flags)
{
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb < 0)
		len_prec -= 1;
	if (nb == 0 && flags.precision == 0)
		return (0);
	real_precision = flags.precision - len_prec;
	if (real_precision > 0)
		print_zero(real_precision);
	else
		real_precision = 0;
	ft_putnbr(positive_nb(nb));
	return (len_nb + real_precision);
}

int	preci_1_width_1_u(long nb, int len_nb, t_flags flags)
{
	int	real_width;
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb < 0)
		len_prec -= 1;
	real_precision = flags.precision - len_prec;
	if (real_precision < 0)
		real_precision = 0;
	real_width = flags.width - determine_plus(nb, flags) - len_nb - real_precision;
	if (real_width < 0)
		real_width = 0;
	if (!flags.precision && !nb)
		return (zero_case(flags));
	if (!flags.minus_sign)
	{
		print_width_space(real_width);
		if (real_precision > 0)
			print_zero(real_precision);
		ft_putnbr(positive_nb(nb));
	}
	else
	{
		if (real_precision > 0)
			print_zero(real_precision);
		ft_putnbr(positive_nb(nb));
		print_width_space(real_width);
	}
	return (len_nb + real_width + real_precision);
}

int	zero_case_u(t_flags flags)
{
	print_width_space(flags.width);
	return (flags.width);
}
