/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxi_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:19:10 by flverge           #+#    #+#             */
/*   Updated: 2023/10/28 11:16:19 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_i_and_d_reload(int n, t_flags flags)
{
	long	nb;
	int		len_nb;
	int		sp_pl;

	nb = n;
	len_nb = int_len_zero(n);
	sp_pl = 0;
	if (!flags.point)
		flags.lenght_print = preci_0(nb, len_nb, flags, sp_pl);
	// else
	// 	flags.lenght_print = preci_1(nb, len_nb, flags, sp_pl);
	return (flags.lenght_print);
}

int	preci_0(long nb, int len_nb, t_flags flags, int sp_pl)
{
	if (!flags.width)
		flags.lenght_print = preci_0_width_0(nb, len_nb, flags, sp_pl);
	// else (flags.width)
	// 	flags.lenght_print = preci_0_width_1(nb, len_nb, flags, sp_pl);
	return (flags.lenght_print);
}

int	preci_0_width_0(long nb, int len_nb, t_flags flags, int sp_pl)
{
	sp_pl = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	return (len_nb + sp_pl);
}

// int	preci_0_width_1(long nb, int len_nb, t_flags flags, int sp_pl)
// {
	
// 	return ();
// }


// int	preci_1(long nb, int len_nb, t_flags flags, int sp_pl) // PAS DE GESTION DES ZEROS
// {
// 	if (!flags.width)
// 		flags.lenght_print = preci_1_width_0(nb, len_nb, flags, sp_pl);
// 	else (flags.width)
// 		flags.lenght_print = preci_1_width_1(nb, len_nb, flags, sp_pl);
// 	return (flags.lenght_print);
// }

// int	preci_1_width_0(long nb, int len_nb, t_flags flags, int sp_pl) // PAS DE GESTION DES ZEROS
// {
	
// }

// int	preci_1_width_1(long nb, int len_nb, t_flags flags, int sp_pl) // PAS DE GESTION DES ZEROS
// {
	
// }

///////////////// OTHERS FUNCTIONS ///////////////////////////////////

