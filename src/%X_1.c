/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %X_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:55:46 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 13:51:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_upx(unsigned int n, t_flags f)
{
	unsigned long	nb;
	int				len_nb;
	int				hashtag;

	nb = n;
	len_nb = intlen_hexa_zero(n);
	hashtag = 0;
	if (!f.point)
		f.lenght_print = preci_0_upx(nb, len_nb, f, hashtag);
	else
		f.lenght_print = preci_1_upx(nb, len_nb, f, hashtag);
	return (f.lenght_print);
}

int	preci_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	if (!f.width)
		f.lenght_print = preci_0_w_0_upx(nb, len_nb, f, hashtag);
	else
		f.lenght_print = preci_0_w_1_upx(nb, len_nb, f, hashtag);
	return (f.lenght_print);
}

int	preci_0_w_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	hashtag = print_hashtag_up(f, nb);
	putnbr_hexa(nb, 'X');
	return (len_nb + hashtag);
}

int	preci_0_w_1_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	int	real_width;

	if (f.minus_sign)
	{
		hashtag = print_hashtag_up(f, nb);
		putnbr_hexa(nb, 'X');
		real_width = f.width - hashtag - len_nb;
		if (real_width > 0)
			print_width_space(real_width);
		else
			real_width = 0;
	}
	else
	{
		if (!f.zero)
		{
			real_width = f.width - determine_hashtag(f, nb) - len_nb;
			if (real_width > 0)
			{
				if (f.zero)
					print_zero(real_width);
				else
					print_width_space(real_width);
			}
			else
				real_width = 0;
			hashtag = print_hashtag_up(f, nb);
			putnbr_hexa(nb, 'X');
		}
		else
		{
			hashtag = print_hashtag_up(f, nb);
			real_width = f.width - hashtag - len_nb;
			if (real_width > 0)
			{
				if (f.zero)
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

int	preci_1_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	if (!f.width)
		f.lenght_print = preci_1_w_0_upx(nb, len_nb, f, hashtag);
	else
		f.lenght_print = preci_1_w_1_upx(nb, len_nb, f);
	return (f.lenght_print);
}

int	preci_1_w_0_upx(unsigned long nb, int len_nb, t_flags f, int hashtag)
{
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	if (nb == 0 && f.precision == 0)
		return (0);
	real_precision = f.precision - len_prec;
	hashtag = print_hashtag_up(f, nb);
	if (real_precision > 0)
		print_zero(real_precision);
	else
		real_precision = 0;
	putnbr_hexa(nb, 'X');
	return (len_nb + hashtag + real_precision);
}

int	preci_1_w_1_upx(unsigned long nb, int len_nb, t_flags f)
{
	int	real_width;
	int	real_precision;
	int	len_prec;

	len_prec = len_nb;
	real_precision = f.precision - len_prec;
	if (real_precision < 0)
		real_precision = 0;
	real_width = f.width - determine_hashtag(f, nb) - len_nb - real_precision;
	if (real_width < 0)
		real_width = 0;
	if (!f.precision && !nb)
		return (zero_case(f));
	if (!f.minus_sign)
	{
		print_width_space(real_width);
		print_hashtag_up(f, nb);
		if (real_precision > 0)
			print_zero(real_precision);
		putnbr_hexa(nb, 'X');
	}
	else
	{
		print_hashtag_up(f, nb);
		if (real_precision > 0)
			print_zero(real_precision);
		putnbr_hexa(nb, 'X');
		print_width_space(real_width);
	}
	return (len_nb + real_width + real_precision);
}
