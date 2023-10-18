/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %u.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:46 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 10:42:47 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_unsigned_int(unsigned int nb)
{
	ft_putnbr_unsigned(nb);
	return (ft_intlen_unsigned(nb));
}
