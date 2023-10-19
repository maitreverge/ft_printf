/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/10/19 15:23:05 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PLACEHOLDERS "%cspdiuxX"
# define START_FLAGS "# +"
# define WIDTH_FLAGS "-0"
# define PRECISION_FLAGS "."

# include <unistd.h>
# include <stdlib.h>


typedef s_struct {
	int plus_sign;
	int space;
	int hashtag;
} t_start_flags;


typedef s_struct {
	int minus_sign;
	int zero;
	unsigned int width;
} t_width_flags;


typedef s_struct {
	int point;
	unsigned int precision;
} t_precision_flags;



int		ft_printf(const char *format, ...);

#endif