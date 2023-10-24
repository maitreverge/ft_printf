/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/10/24 13:03:14 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "lib/libft.h"
# include <stdio.h>

// 10 fields
typedef struct s_flags {
	char	placeholder;
	int		hashtag;
	int		plus_sign;
	int		space;
	int		minus_sign;
	int		zero;
	int		width;
	int		point;
	size_t	precision;
	int		lenght_print;
}	t_flags;

int		ft_printf(const char *format, ...);
int		placeholder_behaviour(t_flags flags, va_list args);

// parsing functions
t_flags	turbo_parsing(const char *format);
t_flags	zero_init_struct(void);
t_flags	first_part_parsing(const char *format, int *i);
t_flags	cleaning_parsing(t_flags f);
int		check_placeholder(char c);

// %c
int		print_char(char c, t_flags flags);

// %s
int		print_string(char *str, t_flags flags);
int		empty_string(char *nul_str, t_flags flags);
int		no_width(char *nul_str);
int		yes_width(char *nul_str, t_flags flags);

// utils
int		width_or_precision(const char *s);
void	print_width_space(int nb);
void	print_width_zero(int nb);
int		pos_width(int width, int lenght);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_struct(t_flags s);

#endif