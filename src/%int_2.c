/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %int_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:56:30 by flverge           #+#    #+#             */
/*   Updated: 2023/10/27 10:37:33 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	no_minus(int nb, int spa_plu, t_flags flags, int polarity)
{
	if (!flags.zero)
		print_width_space(flags.width - int_len_zero(nb) - polarity);
	else
		print_zero(flags.width - int_len_zero(nb) - polarity);
	spa_plu = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	// return (spa_plu + pos_width(flags.width, int_len_zero(nb)));
	return (pos_width(flags.width, (int_len_zero(nb) + spa_plu + polarity)) + int_len_zero(nb));
}

int	yes_minus(int nb, int spa_plu, t_flags flags, int polarity)
{
	spa_plu = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	if (!flags.zero)
		print_width_space(flags.width - (int_len_zero(nb) + spa_plu) - polarity);
	else
		print_zero(flags.width - (int_len_zero(nb) + spa_plu) + polarity);
	return (pos_width(flags.width, (int_len_zero(nb) + spa_plu + polarity)) + int_len_zero(nb));
}

int	no_precision(int nb, int len_nb, t_flags flags)
{
	int	spa_plu;
	int	polarity;

	spa_plu = 0;
	polarity = 0;
	if (nb < 0)
		polarity = 1;
	if (!flags.width)
	{
		spa_plu = print_plus_or_space(nb, flags);
		ft_putnbr(nb);
		flags.lenght_print = (spa_plu + len_nb);
	}
	else
	{
		if (!flags.minus_sign)
			flags.lenght_print = no_minus(nb, spa_plu, flags, polarity);
		else
			flags.lenght_print = yes_minus(nb, spa_plu, flags, polarity);
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