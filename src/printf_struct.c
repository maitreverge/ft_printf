/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 10:55:53 by flverge           #+#    #+#             */
/*   Updated: 2023/10/31 17:09:08 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_struct(t_flags s)
{
	printf("placeholder = %c\n---\n", s.placeholder);
	printf("hashtag = %i\n---\n", s.hashtag);
	printf("plus_sign = %i\n---\n", s.plus_sign);
	printf("space = %i\n---\n", s.space);
	printf("minus_sign = %i\n---\n", s.minus_sign);
	printf("zero = %i\n---\n", s.zero);
	printf("point = %i\n---\n", s.point);
	printf("width = %i\n---\n", s.width);
	printf("precision = %i\n---\n", s.precision);
}

int	check_flags(char c)
{
	if (c == '#' || c == ' ' || c == '+' || c == '-')
		return (1);
	return (0);
}
