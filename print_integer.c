/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:55:22 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:57:27 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_integer(char *str_from_arg, t_format *format,
t_lengths *lengths)
{
	int	diff;

	diff = get_diff(format, lengths);
	if (str_from_arg[0] == '-')
		ft_print_negative(str_from_arg, format, lengths, diff);
	else
		ft_print_positive(str_from_arg, format, lengths, diff);
}

void	ft_print_positive(char *str_from_arg, t_format *format,
t_lengths *lengths, int diff)
{
	if (format->flag_minus)
	{
		ft_putnchar('0', diff);
		if (format->precision != 0 || str_from_arg[0] != '0')
			ft_putstr_fd(str_from_arg, 1);
		if (format->width > lengths->arg_length)
		{
			ft_putnchar(' ', lengths->res_length - lengths->arg_length - diff);
			if (str_from_arg[0] == '0' && diff == 0 && format->p_has_changed)
				write(1, " ", 1);
		}
	}
	else
	{
		if (format->width > lengths->arg_length)
			di_handle_width(str_from_arg, format, lengths, diff);
		else
		{
			ft_putnchar('0', diff);
			if (format->precision != 0 || str_from_arg[0] != '0')
				ft_putstr_fd(str_from_arg, 1);
		}
	}
}

void	di_handle_width(char *str_from_arg, t_format *format,
t_lengths *lengths, int diff)
{
	if (format->flag_zero && diff == 0)
	{
		if (format->precision != 0 && format->p_has_changed)
			ft_putnchar(' ', lengths->res_length - lengths->arg_length);
		if (format->precision == 0 || !format->p_has_changed)
		{
			ft_putnchar('0', lengths->res_length - lengths->arg_length);
			if (str_from_arg[0] == '0' && format->precision != 0)
				write(1, "0", 1);
		}
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - lengths->arg_length - diff);
		if (str_from_arg[0] == '0' && format->precision != 0 && diff == 0)
			write(1, "0", 1);
		else if (str_from_arg[0] == '0' && format->precision == 0)
			write(1, " ", 1);
	}
	ft_putnchar('0', diff);
	if ((format->p_has_changed && format->precision != 0)
		|| str_from_arg[0] != '0')
		ft_putstr_fd(str_from_arg, 1);
}

int	get_diff(t_format *format, t_lengths *lengths)
{
	int	diff;

	diff = format->precision - lengths->arg_length;
	if (diff < 0)
		diff = 0;
	return (diff);
}
