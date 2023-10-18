/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 10:42:27 by flverge           #+#    #+#             */
/*   Updated: 2023/10/07 11:42:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar((nb % 10) + 48);
}

void	ft_putnbr_hexa_adress(unsigned long long nb)
{
	// if (nb < 0)
	// 	ft_putnbr_hexa_adress(nb * -1);
	if (nb > 15)
		ft_putnbr_hexa_adress(nb / 16);
	ft_putchar("0123456789abcdef"[(nb % 16)]);
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	ft_putchar((nb % 10) + 48);
}

void	ft_putnbr_hexa_low(unsigned int nb)
{
	if (nb > 15)
		ft_putnbr_hexa_low(nb / 16);
	ft_putchar("0123456789abcdef"[nb % 16]);
}

void	ft_putnbr_hexa_big(unsigned int nb)
{
	if (nb > 15)
		ft_putnbr_hexa_big(nb / 16);
	ft_putchar("0123456789ABCDEF"[nb % 16]);
}
