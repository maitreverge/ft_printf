/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   %s.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 11:36:59 by flverge           #+#    #+#             */
/*   Updated: 2023/10/23 11:00:28 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

int	print_string(char *str, t_flags flags)
{
	int		len_str;

	if (!str)
	{
		if (flags.point && flags.precision < 6)
		{
			if (!flags.width)
				return (0);
			else
			{
				print_width_space(flags.width);
				return (flags.width);
			}
		}
		if (flags.point && flags.precision >= 6)
		{
			if (!flags.width)
			{
				ft_putstr("(null)");
				return (6);
			}
			else
			{
				if (flags.minus_sign)
				{
					ft_putstr("(null)");
					print_width_space(flags.width - 6);
				}
				else
				{
					print_width_space(flags.width - 6);
					ft_putstr("(null)");
				}
				if (flags.width > 6)
					return ();
			}
		}
	}
	len_str = ft_strlen(str);
}
		}
	}
	len_str = ft_strlen(str);
}

/*
! Commencer par la precision, car elle influence la width


*/
