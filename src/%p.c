/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %p.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:43:00 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 10:43:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_adress(unsigned long long adress)
{
	ft_putstr("0x");
	if (adress == 0)
	{
		ft_putchar('0');
		return (3);
	}
	else if (adress == (unsigned long long)-1)
	{
		ft_putstr("ffffffffffffffff");
		return (18);
	}
	ft_putnbr_hexa_adress(adress);
	return (ft_intlen_hexa(adress) + 2);
}

/*
Adresses are just long converted into hexa with suffix 0x
*/