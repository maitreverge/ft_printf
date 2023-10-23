/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/10/23 13:14:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

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
	int		precision;
	int		lenght_print;
}	t_flags;

int		ft_printf(const char *format, ...);

// parsing functions
t_flags	turbo_parsing(char *format);
t_flags	zero_init_struct(void);
t_flags	first_part_parsing(char *format, int *i);
t_flags	cleaning_parsing(t_flags f);

// %c
int		print_char(char c, t_flags flags);

// %s
int		print_string(char *str, t_flags flags);
static int	empty_string(char *nul_str, t_flags flags);
static int	no_width(char *nul_str, t_flags flags);
static int	yes_width(char *nul_str, t_flags flags);

// utils
void	print_width_space(int nb);
void	print_width_zero(int nb);
int		pos_width(int width, int lenght);

#endif