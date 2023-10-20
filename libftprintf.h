/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/10/20 16:21:01 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PLACEHOLDERS "cspdiuxX%"  // Vraiment utile ??
# define FLAGS "#+ -0."

# include <unistd.h>
# include <stdlib.h> // malloc ses grands morts
# include <stdarg.h> // va_arg


// 9 fields
typedef struct s_flags {
	char placeholder;
	int hashtag;
	int plus_sign;
	int space;
	int minus_sign;
	int zero;
	int point;
	int width;
	int precision;
} t_flags;


int		ft_printf(const char *format, ...);

t_flags	zero_init_struct(void);
f_flags	turbo_parsing(char *format);

int is_placeholder(char c);

#endif