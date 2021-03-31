/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:53:49 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:54:01 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (lengths->res_length == 1)
		write(1, str_from_arg, 1);
	else
	{
		if (format->flag_minus == 1)
		{
			write(1, str_from_arg, 1);
			ft_putnchar(' ', lengths->res_length - 1);
		}
		else
		{
			if (format->flag_zero == 1)
			{
				ft_putnchar('0', lengths->res_length - 1);
				write(1, str_from_arg, 1);
			}
			else
			{
				ft_putnchar(' ', lengths->res_length - 1);
				write(1, str_from_arg, 1);
			}
		}
	}
}
