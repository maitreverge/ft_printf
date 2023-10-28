/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %int_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:56:30 by flverge           #+#    #+#             */
/*   Updated: 2023/10/28 11:10:29 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_width_int(int nb, int len_nb, t_flags flags)
{
	int	space_plus_flag;
	int	precision;

	precision = flags.precision - len_nb;
	space_plus_flag = print_plus_or_space(nb, flags);
	if (nb == 0 && !flags.precision && !flags.width)
		return (0);
	if (nb < 0)
		ft_putchar('-');
	if (precision > 0)
		print_zero(precision);
	if (nb < 0 && nb != FT_INT_MIN)
		ft_putnbr(nb * (-1));
	if (nb == FT_INT_MIN)
		ft_putstr("2147483648");
	if (nb >= 0)
		ft_putnbr(nb);
	if (precision < 0)
		precision = 0;
	flags.lenght_print = len_nb + precision;
	return (space_plus_flag + flags.lenght_print);
}

// ! gestion des zeros qui me brisent les couilles
int	yes_width_int(int nb, int len_nb, t_flags flags)
{
	int		space_plus_flag;
	int		precision;
	int		polarity;

	polarity = 0;
	if (nb < 0)
		polarity = 1;
	precision = flags.precision - len_nb;
	if (precision < 0)
		precision = 0;
	if (flags.minus_sign)
	{
		flags.lenght_print = len_nb + precision;
		space_plus_flag = print_plus_or_space(nb, flags);
		if (nb < 0)
			ft_putchar('-');
		if (precision > 0)
			print_zero(precision);
		if (nb < 0 && nb != FT_INT_MIN)
			ft_putnbr(nb * (-1));
		if (nb == FT_INT_MIN)
			ft_putstr("2147483648");
		if (nb >= 0)
			ft_putnbr(nb);
		print_width_space(flags.width - (flags.lenght_print + polarity));
		return (space_plus_flag + pos_width(flags.width, flags.lenght_print) + precision + len_nb);
	}
	flags.lenght_print = len_nb + precision;
	space_plus_flag = print_plus_or_space(nb, flags);
	if (nb < 0)
		ft_putchar('-');
	print_width_space(flags.width - flags.lenght_print);
	if (precision > 0)
		print_zero(precision);
	if (nb < 0 && nb != FT_INT_MIN)
		ft_putnbr(nb * (-1));
	if (nb == FT_INT_MIN)
		ft_putstr("2147483648");
	if (nb >= 0)
		ft_putnbr(nb);
	return (space_plus_flag + pos_width(flags.width, flags.lenght_print));
}

int	yes_precision(int nb, int len_nb, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = no_width_int(nb, len_nb, flags);
	else
		flags.lenght_print = yes_width_int(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	print_i_and_d(int nb, t_flags flags)
{
	int	len_nb;
	int	polarity;

	if (nb < 0)
		polarity = 1;
	else
		polarity = 0;
	len_nb = int_len_zero(nb);
	if (flags.point)
		flags.lenght_print = yes_precision(nb, len_nb, flags);
	else
		flags.lenght_print = no_precision(nb, len_nb, flags);
	return (flags.lenght_print + polarity);
}
