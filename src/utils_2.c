/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:27:45 by flverge           #+#    #+#             */
/*   Updated: 2023/10/25 10:39:52 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int n)
{
	int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_strndup(const char *s, size_t n)
{
	unsigned int	i;
	char			*str;

	str = ft_calloc(n + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
