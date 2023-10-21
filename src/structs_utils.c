/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:58:03 by flverge           #+#    #+#             */
/*   Updated: 2023/10/21 13:24:28 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_flags	zero_init_struct(void)
{
	t_flags	f;

	f.placeholder = 0;
	f.hashtag = 0;
	f.plus_sign = 0;
	f.space = 0;
	f.minus_sign = 0;
	f.zero = 0;
	f.width = 0;
	f.point = 0;
	f.precision = 0;
	return (f);
}

t_flags	cleaning_parsing(t_flags f)
{
	if (f.plus_sign == 1 && f.space == 1)
	{
		f.plus_sign = 0;
		f.space = 0;
	}
	if (f.hashtag > 1)
		f.hashtag = 0;
	if (f.plus_sign > 1)
		f.plus_sign = 0;
	if (f.space > 1)
		f.space = 0;
	if (f.minus_sign > 1)
		f.minus_sign = 0;
	if (f.zero > 1)
		f.zero = 0;
	if (f.point > 1)	
		f.point = 0;
	return (f);
}
