/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:54:14 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:54:40 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(char *str_from_arg, t_format *format,
t_lengths *lengths)
{
	if (lengths->res_length == lengths->arg_length)
		ft_putstr_fd(str_from_arg, 1);
	else if (format->flag_minus)
	{
		print_address(format, lengths, str_from_arg);
		ft_putnchar(' ', lengths->res_length - lengths->arg_length - 2);
	}
	else if (format->flag_zero)
	{
		ft_putnchar('0', lengths->res_length - format->precision
		- lengths->arg_length);
		print_address(format, lengths, str_from_arg);
	}
	else
	{
		if (format->width > lengths->arg_length && (lengths->arg_length != 0
				|| format->precision == 0))
			ft_putnchar(' ', lengths->res_length - lengths->arg_length - 2);
		else
			ft_putnchar(' ', lengths->res_length - lengths->arg_length - 3);
		print_address(format, lengths, str_from_arg);
	}
}

void	print_address(t_format *format, t_lengths *lengths, char *str)
{
	write(1, "0x", 2);
	if (format->p_has_changed && format->precision > 0)
		ft_putnchar('0', lengths->res_length - format->precision);
	else if ((str[0] == '\0' || lengths->res_length == 3)
		&& format->precision != 0)
		write(1, "0", 1);
	ft_putstr_fd(str, 1);
}
