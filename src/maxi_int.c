/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxi_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:19:10 by flverge           #+#    #+#             */
/*   Updated: 2023/10/28 10:31:02 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i_and_d(int nb, t_flags flags)
{
	int	len_nb;

	len_nb = int_len_zero(nb);
	if (!flags.point)
		flags.lenght_print = preci_0(nb, len_nb, flags);
	else
		flags.lenght_print = preci_1(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_0(int nb, int len_nb, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = preci_0_width_0(nb, len_nb, flags);
	else (flags.width)
		flags.lenght_print = preci_0_width_1(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_0_width_0(int nb, int len_nb, t_flags flags)
{
	
}

int	preci_0_width_1(int nb, int len_nb, t_flags flags)
{
	
}


int	preci_1(int nb, int len_nb, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = preci_1_width_0(nb, len_nb, flags);
	else (flags.width)
		flags.lenght_print = preci_1_width_1(nb, len_nb, flags);
	return (flags.lenght_print);
}

int	preci_1_width_0(int nb, int len_nb, t_flags flags)
{
	
}

int	preci_1_width_1(int nb, int len_nb, t_flags flags)
{
	
}