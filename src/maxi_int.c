/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxi_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 10:19:10 by flverge           #+#    #+#             */
/*   Updated: 2023/10/28 12:32:53 by flverge          ###   ########.fr       */
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
	else
		flags.lenght_print = preci_0_width_1(nb, len_nb, flags, sp_pl);
	return (flags.lenght_print);
}

int	preci_0_width_0(long nb, int len_nb, t_flags flags, int sp_pl)
{
	sp_pl = print_plus_or_space(nb, flags);
	ft_putnbr(nb);
	return (len_nb + sp_pl);
}

int	preci_0_width_1(long nb, int len_nb, t_flags flags, int sp_pl)
{
	int real_width;

	if (flags.minus_sign) // PAS DE GESTION DE ZERO
	{
		sp_pl = print_plus_or_space(nb, flags);
		
		ft_putnbr(nb);
		
		real_width = flags.width - sp_pl - len_nb;
		if (real_width > 0)
			print_width_space(real_width);
		else
			real_width = 0;		
	}
	else // GESTION DES ZEROS
	{
		if (!flags.zero)
		{
			real_width = flags.width - determine_plus_or_space(nb, flags) - len_nb;
			if (real_width > 0)
			{
				if (flags.zero)
					print_zero(real_width);
				else
					print_width_space(real_width);
			}
			else
				real_width = 0;

			sp_pl = print_plus_or_space(nb, flags);

			ft_putnbr(nb);
		}
		else // Si il y a un zero
		{
			sp_pl = print_plus_or_space(nb, flags);

			if (nb < 0)
				ft_putchar('-');
			
			real_width = flags.width - sp_pl - len_nb;
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
	return (len_nb + sp_pl + real_width);
}




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

