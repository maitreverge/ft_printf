/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:37:35 by flverge           #+#    #+#             */
/*   Updated: 2023/10/24 13:33:10 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	width_or_precision(const char *s)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (ft_isdigit(s[i]))
	{
		result = (10 * result) + (s[i] - 48);
		i++;
	}
	return (result);
}

void	print_width_space(int nb)
{
	int	i;

	i = 0;
	if (nb < i)
		return ;
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
	if (nb < i)
		return ;
	while (i < nb)
	{
		ft_putchar('0');
		i++;
	}
}

int	pos_width(int width, int lenght)
{
	if (width < lenght)
		return (0);
	return (width - lenght);
}

int	count_flags(t_flags s)
{
	int	result;

	result = s.hashtag + s.minus_sign + s.plus_sign
		+ s.point + s.space + s.zero
		+ int_len(s.width) + int_len(s.precision) + 1;
	return (result);
}
