/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/10/19 17:01:11 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PLACEHOLDERS "%cspdiuxX"
# define FLAGS "# +"
# define WIDTH_FLAGS "-0"
# define PRECISION_FLAGS "."

# include <unistd.h>
# include <stdlib.h> // malloc ses grands morts
# include <stdarg.h> // va_arg


typedef struct s_flags {
	int hashtag;
	int plus_sign;
	int space;
	int minus_sign;
	int zero;
	unsigned int width;
	int point;
	unsigned int precision;
} t_flags;


int		ft_printf(const char *format, ...);

#endif