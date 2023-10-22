/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:37:35 by flverge           #+#    #+#             */
/*   Updated: 2023/10/22 12:14:02 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	width_or_precision(char *s)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (is_digit(s[i]))
	{
		result = (10 * result) + ft_atoi(s[i]);
		i++;
	}
	return (result);
}

void	print_width_space(int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
}

void	print_width_zero(int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		ft_putchar('0');
		i++;
	}
}
