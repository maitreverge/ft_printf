/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/10/30 10:56:59 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h> // DO NOT FORGET TO DELETE LATER

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

// 10 fields
typedef struct s_flags {
	char	placeholder;
	int		hashtag;
	int		plus_sign;
	int		space;
	int		minus_sign;
	int		zero;
	int		width;
	int		width_zeros;
	int		point;
	int		precision;
	int		precision_zeros;
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

// %p
int		print_adress(unsigned long nb, t_flags flags);
int		yes_width_hexa(char *prefix, t_flags flags, unsigned long nb);
int		empty_adress(char *nul_str, t_flags flags);
void	putnbr_hexa_adress(unsigned long nb);
int		intlen_hexa(unsigned long n);

// %i && %d FIRST TRY
int		print_i_and_d(int nb, t_flags flags);
int		yes_precision(int nb, int len_nb, t_flags flags);
int		no_precision(int nb, int len_nb, t_flags flags);
int		yes_width_int(int nb, int len_nb, t_flags flags);
int		no_width_int(int nb, int len_nb, t_flags flags);
int		yes_minus(int nb, int space_plus_flag, t_flags flags, int polarity);
int		no_minus(int nb, int space_plus_flag, t_flags flags, int polarity);

// %i && %d SECOND TRY
int		print_i_and_d_reload(int nb, t_flags flags);
int		preci_0(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_0_width_0(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_0_width_1(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_1(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_1_width_0(long nb, int len_nb, t_flags flags, int sp_pl);
int		preci_1_width_1(long nb, int len_nb, t_flags flags, int sp_pl);

long		positive_nb(long nb);
int	determine_plus_or_space(long nb, t_flags flags);











// %u

// %x && %X


// utils


void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);


int		check_flags(char c);
int		width_or_precision(const char *s);
void	print_width_space(int nb);
void	print_zero(int nb);
int		pos_width(int width, int lenght);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	print_struct(t_flags s);
int		int_len(long n);
int		int_len_zero(long n);
int		count_flags(t_flags s);
char	*ft_strndup(const char *s, size_t n);
void	ft_putnbr(long nb);
int		print_plus_or_space(long nb, t_flags flags);


#endif