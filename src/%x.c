/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %x.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:40 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 10:42:41 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_hexa(unsigned int nb, char c)
{
	if (c == 'x')
		ft_putnbr_hexa_low(nb);
	else
		ft_putnbr_hexa_big(nb);
	return (ft_intlen_hexa_10(nb));
}
