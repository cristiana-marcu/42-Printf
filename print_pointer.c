/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:54:14 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/06 17:59:33 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(char *str_from_arg, t_format *format,
t_lengths *lengths)
{
	if (lengths->res_length - 2 == lengths->arg_length
		&& str_from_arg[0] != '\0')
	{
		write(1, "0x", 2);
		if (str_from_arg[0] == '0' && format->precision == 0)
			return ;
		else
			ft_putstr_fd(str_from_arg, 1);
	}
	else if (format->flag_minus)
	{
		print_address(format, lengths, str_from_arg);
		spaces_to_print(format, lengths, str_from_arg);
	}
	else if (format->flag_zero)
	{
		ft_putnchar('0', lengths->res_length - format->precision
		- lengths->arg_length);
		print_address(format, lengths, str_from_arg);
	}
	else
	{
		spaces_to_print(format, lengths, str_from_arg);
		print_address(format, lengths, str_from_arg);
	}
}

void	print_address(t_format *format, t_lengths *lengths, char *str)
{
	write(1, "0x", 2);
	if (format->p_has_changed && format->precision > 0)
		ft_putnchar('0', lengths->res_length - format->precision);
	else if ((str[0] == '\0' || lengths->arg_length == 0)
		&& format->precision != 0)
		write(1, "0", 1);
	if (format->precision != 0)
		ft_putstr_fd(str, 1);
}

void	spaces_to_print(t_format *format, t_lengths *lengths, char *str_from_arg)
{
	if (format->width > lengths->arg_length && (lengths->arg_length != 0
			|| format->precision == 0))
	{
		if (str_from_arg[0] == '0' && format->precision == 0)
			ft_putnchar(' ', lengths->res_length - lengths->arg_length - 1);
		else
			ft_putnchar(' ', lengths->res_length - lengths->arg_length - 2);
	}
	else
		ft_putnchar(' ', lengths->res_length - lengths->arg_length - 3);
}
