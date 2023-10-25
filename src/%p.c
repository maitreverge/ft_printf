/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %p.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:01:58 by flverge           #+#    #+#             */
/*   Updated: 2023/10/25 16:55:56 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	intlen_hexa(unsigned long n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	putnbr_hexa_adress(unsigned long nb)
{
	if (nb > 15)
		putnbr_hexa_adress(nb / 16);
	ft_putchar("0123456789abcdef"[(nb % 16)]);
}

int	empty_adress(char *nul_str, t_flags flags)
{
	if (!flags.width)
		flags.lenght_print = no_width(nul_str);
	else
		flags.lenght_print = yes_width(nul_str, flags);
	return (flags.lenght_print);
}

int	yes_width_hexa(char *prefix, t_flags flags, unsigned long nb)
{
	if (flags.minus_sign)
	{
		ft_putstr(prefix);
		putnbr_hexa_adress(nb);
		print_width_space(flags.width - (ft_strlen(prefix) + intlen_hexa(nb)));
	}
	else
	{
		print_width_space(flags.width - (ft_strlen(prefix) + intlen_hexa(nb)));
		ft_putstr(prefix);
		putnbr_hexa_adress(nb);
	}
	// VALEURS DE RETOUR ERRONEES
	return (flags.width + (2 + int_len(nb)));
}

int	print_adress(unsigned long nb, t_flags flags)
{
	char	*prefix;

	if (nb == 0)
		return (empty_adress("(nil)", flags));
	prefix = "0x";
	if (!flags.width)
	{
		ft_putstr(prefix);
		putnbr_hexa_adress(nb);
		flags.lenght_print = (intlen_hexa(nb) + ft_strlen(prefix));
	}
	else
		flags.lenght_print = yes_width_hexa(prefix, flags, nb);
	return (flags.lenght_print);
}
