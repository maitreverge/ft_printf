/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:58:03 by flverge           #+#    #+#             */
/*   Updated: 2023/10/20 15:55:17 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_flags	zero_init_struct()
{
	t_flags f;
	
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

