/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:46:36 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/06 13:27:17 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_string_length(char *str_from_arg, t_format *format)
{
	int	res_length;

	res_length = ft_strlen(str_from_arg);
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width *= -1;
	}
	if (format->precision < 0)
		format->precision = res_length;
	if (format->width > format->precision && format->width > res_length
		&& format->precision >= res_length)
		res_length = format->width;
	else if (format->width > res_length || (format->width > format->precision
			&& format->p_has_changed))
		res_length = format->width;
	else if (format->precision < res_length && res_length != 0
		&& format->p_has_changed)
		res_length = format->precision;
	else if (format->precision == 0)
		res_length = 0;
	return (res_length);
}

int	ft_get_char_length(t_format *format)
{
	int	res_length;

	res_length = 1;
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width *= -1;
	}
	if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

int	ft_get_pointer_length(t_format *format, char *str_from_arg)
{
	int	res_length;

	res_length = ft_strlen(str_from_arg) + 2;
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width *= -1;
	}
	if (res_length == 2)
	{
		if ((!format->p_has_changed && format->precision != 0)
			|| format->precision < 0)
			res_length = 3;
	}
	if (format->precision > res_length)
		res_length = format->precision + 2;
	else if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

int	ft_get_integer_length(char *str_from_arg, t_format *format)
{
	int	length;

	length = ft_strlen(str_from_arg);
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width *= -1;
	}
	if (format->precision >= format->width && format->p_has_changed)
	{
		if (str_from_arg[0] == '-' && format->precision >= length - 1)
			length = format->precision + 1;
		else if (format->precision >= length)
			length = format->precision;
		else if (format->precision == 0 && str_from_arg[0] == '0')
			length = 0;
	}
	else if (format->width > length)
		length = format->width;
	return (length);
}

int	ft_get_unsigned_length(char *str_from_arg, t_format *format)
{
	int	length;

	length = ft_strlen(str_from_arg);
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width *= -1;
	}
	/*if (format->precision < 0)
		length = 1;*/
	if (format->precision >= format->width && format->p_has_changed)
	{
		if (format->precision >= length)
			length = format->precision;
		else if (format->precision == 0 && str_from_arg[0] == '0')
			length = 0;
	}
	else if (format->width > length)
		length = format->width;
	return (length);
}
