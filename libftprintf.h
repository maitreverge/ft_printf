/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nope <nope@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:22:30 by florianverg       #+#    #+#             */
/*   Updated: 2023/09/12 12:44:09 by nope             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_print_char(char c); // %c & %%
int		ft_print_string(char *s); // %s
int		ft_print_adress(unsigned long long adress); // %p
int		ft_print_unsigned_int(unsigned int nb); // %u
int		ft_print_int(int nb); // %i && %d
int		ft_print_hexa(unsigned int nb, char c); // %x

void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putnbr(int nb);
int		ft_abs(int c);

void	ft_putnbr_unsigned(unsigned int nb);
void	ft_putnbr_hexa_adress(unsigned long long nb);
void	ft_putnbr_hexa_low(unsigned int nb);
void	ft_putnbr_hexa_big(unsigned int nb);

int		ft_intlen(int n);
int		ft_intlen_hexa(unsigned long long n);
int		ft_intlen_unsigned(unsigned int n);
int		ft_intlen_hexa_10(unsigned int n);

#endif