/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %int_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:56:30 by flverge           #+#    #+#             */
/*   Updated: 2023/10/26 15:36:43 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_minus(int nb, int space_plus_flag, t_flags flags)
{
	if (!flags.zero)
		print_zero(flags.width - flags.lenght_print);
	else
		print_width_space(flags.width - flags.lenght_print);
	space_plus_flag = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	return (space_plus_flag + pos_width(flags.width, flags.lenght_print));
}

int	yes_minus(int nb, int space_plus_flag, t_flags flags)
{
	space_plus_flag = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	if (!flags.zero)
		print_zero(flags.width - flags.lenght_print);
	else
		print_width_space(flags.width - flags.lenght_print);
	return (space_plus_flag + pos_width(flags.width, flags.lenght_print));
}

int	no_precision(int nb, int len_nb, t_flags flags)
{
	int	space_plus_flag;

	space_plus_flag = 0;
	if (!flags.width)
	{
		space_plus_flag = print_plus_or_space(nb, flags);
		ft_putnbr(nb);
		flags.lenght_print = (space_plus_flag + len_nb);
	}
	else
	{
		if (!flags.minus_sign)
			flags.lenght_print = no_minus(nb, space_plus_flag, flags);
		else
			flags.lenght_print = yes_minus(nb, space_plus_flag, flags);
	}
	return (flags.lenght_print);
}











/*
int	print_i_and_d(int nb, t_flags flags)
{
	int	len_nb;

	len_nb = int_len(nb);
	// pas de gestion du flag 0
	if (flags.point)
		flags.lenght_print = yes_precision(nb, len_nb, flags);
	else
		flags.lenght_print = no_precision(nb, len_nb, flags);
	return (flags.lenght_print);



*/