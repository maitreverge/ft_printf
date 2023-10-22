/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/10/22 12:15:36 by flverge          ###   ########.fr       */
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
	char	placeholder;
	int		hashtag;
	int		plus_sign;
	int		space;
	int		minus_sign;
	int		zero;
	int		point;
	int		width;
	int		precision;
}	t_flags;


int		ft_printf(const char *format, ...);

t_flags	turbo_parsing(char *format);
t_flags	zero_init_struct(void);
t_flags	first_part_parsing(char *format, int *i);
t_flags	cleaning_parsing(t_flags f);

int		print_char(char c, t_flags flags);

void	print_width_space(int nb);
void	print_width_zero(int nb);


#endif