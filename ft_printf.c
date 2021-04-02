/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:42:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/02 15:30:19 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		vl;
	t_format	format;
	t_lengths	lengths;
	int			result;

	va_start(vl, str);
	result = ft_string_looper(&vl, &format, &lengths, str);
	va_end(vl);
	return (result);
}

int	ft_string_looper(va_list *vl, t_format *format, t_lengths *lengths,
const char *str)
{
	int		i;
	int		result;
	char	*str_from_arg;

	i = 0;
	result = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_format(format);
			i += ft_check_formatters(vl, (char *)str, i, format);
			str_from_arg = ft_arg_to_string(vl, format);
			ft_init_lengths(lengths, str_from_arg, format);
			ft_print_arg(str_from_arg, format, lengths);
			result += lengths->res_length;
		}
		if (str[i] != '\0' && str[i] != '%')
		{
			write(1, &str[i], 1);
			i++;
			result++;
		}
	}
	return (result);
}

int	ft_get_length(char *str_from_arg, t_format *format)
{
	int	res_length;

	res_length = 0;
	if (format->specifier == 's')
		res_length = ft_get_string_length(str_from_arg, format);
	else if (format->specifier == 'c' || format->specifier == '%')
		res_length = ft_get_char_length(format);
	else if (format->specifier == 'p')
		res_length = ft_get_pointer_length(format, str_from_arg);
	else if (format->specifier == 'd' || format->specifier == 'i')
		res_length = ft_get_integer_length(str_from_arg, format);
	else if (format->specifier == 'u' || format->specifier == 'x'
		|| format->specifier == 'X')
		res_length = ft_get_unsigned_length(str_from_arg, format);
	return (res_length);
}

void	ft_print_arg(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (format->specifier == 's')
		ft_print_string(str_from_arg, format, lengths);
	else if (format->specifier == 'c' || format->specifier == '%')
		ft_print_char(str_from_arg, format, lengths);
	else if (format->specifier == 'p')
		ft_print_pointer(str_from_arg, format, lengths);
	else if (format->specifier == 'd' || format->specifier == 'i')
		ft_print_integer(str_from_arg, format, lengths);
	else if (format->specifier == 'u')
		ft_print_unsigned(str_from_arg, format, lengths);
	else if (format->specifier == 'x' || format->specifier == 'X')
		ft_print_hex(str_from_arg, format, lengths);
}
