/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:57:22 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:57:43 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_negative(char *str_from_arg, t_format *format,
t_lengths *lengths, int diff)
{
	char	*substr;

	substr = str_from_arg + 1;
	if (format->flag_minus)
		ft_handle_minusflag_neg(substr, format, lengths, diff);
	else
	{
		if (format->width > lengths->arg_length)
			di_handle_neg_width(substr, format, lengths, diff);
		else
		{
			write(1, "-", 1);
			ft_putnchar('0', diff);
			if (format->precision >= lengths->arg_length)
				write(1, "0", 1);
			if (format->precision != 0)
				ft_putstr_fd(substr, 1);
		}
	}
}

void	ft_handle_minusflag_neg(char *substr, t_format *format,
t_lengths *lengths, int diff)
{
	write(1, "-", 1);
	ft_putnchar('0', diff);
	if (format->precision >= lengths->arg_length)
		write(1, "0", 1);
	if (format->precision != 0)
		ft_putstr_fd(substr, 1);
	if (format->width > lengths->arg_length)
	{
		if (diff == 1)
			diff = 2;
		ft_putnchar(' ', lengths->res_length - lengths->arg_length - diff);
	}
}

void	di_handle_neg_width(char *str_from_arg, t_format *format,
t_lengths *lengths, int diff)
{
	if (format->flag_zero && diff == 0)
	{
		if (format->precision != 0 && format->p_has_changed)
			ft_putnchar(' ', lengths->res_length - lengths->arg_length);
		write(1, "-", 1);
		if (format->precision >= lengths->arg_length)
			write(1, "0", 1);
		if (format->precision == 0 || !format->p_has_changed)
			ft_putnchar('0', lengths->res_length - lengths->arg_length);
	}
	else
	{
		if (diff == 1)
			diff = 2;
		ft_putnchar(' ', lengths->res_length - lengths->arg_length - diff);
		write(1, "-", 1);
	}
	ft_putnchar('0', diff);
	if ((format->p_has_changed && format->precision != 0)
		|| str_from_arg[0] != '0')
		ft_putstr_fd(str_from_arg, 1);
}