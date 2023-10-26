/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %p.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:01:58 by flverge           #+#    #+#             */
/*   Updated: 2023/10/26 10:52:03 by flverge          ###   ########.fr       */
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
	int	len_prefix;
	int	len_nb;
	int	total_len;

	len_prefix = ft_strlen(prefix);
	len_nb = intlen_hexa(nb);
	total_len = len_nb + len_prefix;
	if (flags.minus_sign)
	{
		ft_putstr(prefix);
		putnbr_hexa_adress(nb);
		print_width_space(flags.width - total_len);
	}
	else
	{
		print_width_space(flags.width - total_len);
		ft_putstr(prefix);
		putnbr_hexa_adress(nb);
	}
	return (total_len + pos_width(flags.width, total_len));

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