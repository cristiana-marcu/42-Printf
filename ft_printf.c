/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:42:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/11 18:37:05 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_printf(char *str, ...)
{
	va_list vl;
	int		i;
	t_format format;
	t_lengths lengths;
	char	*str_from_arg;

	va_start(vl, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_format(&format);
			i += ft_check_formatters(&vl, str, i, &format);
			str_from_arg = ft_arg_to_string(&vl, &format);
			lengths.res_length = ft_get_length(str_from_arg, &format);
			lengths.arg_length = ft_strlen(str_from_arg);
			ft_print_arg(str_from_arg, &format, &lengths);
			i++;
		}
		if (str[i] != '\0')
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	va_end(vl);
	return (i);
}

char	*ft_arg_to_string(va_list *vl, t_format *format)
{
	char					*str_from_arg;
	unsigned long long int	toprint;
	void					*arg;

	if (format->specifier == 's')
		str_from_arg = va_arg(*vl, char *);
	else if (format->specifier == 'c' || format->specifier == '%')
		str_from_arg = va_arg(*vl, char *);
	else if (format->specifier == 'p')
	{
		arg = va_arg(*vl, void *);
		toprint = (unsigned long long int)&arg;
		str_from_arg = ft_itoa_hex(toprint);
	}
	else if (format->specifier == 'd' || format->specifier == 'i')
		str_from_arg = ft_itoa(va_arg(*vl, int));
	else if (format->specifier == 'u' || format->specifier == 'x'
			|| format->specifier == 'X')
		str_from_arg = ft_itoa_hex(va_arg(*vl, unsigned int));
	else
		str_from_arg = "";
	return (str_from_arg);
}

void ft_init_format(t_format *format)
{
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->width = 0;
	format->precision = 1;
	format->specifier = '\0';
}

void ft_get_flags(char *str, int i, t_format *format)
{
	if (str[i] == '-')
	{
		if (format->flag_zero == 1)
			format->flag_zero = 0;
		format->flag_minus = 1;
		return ;
	}
	else
	{
		if (format->flag_minus == 1)
			format->flag_zero = 0;
		format->flag_zero = 1;
	}
}

int ft_check_formatters(va_list *vl, char *str, int i, t_format *format)
{
	int result;

	result = 1;
	i++;
	while (str[i] == '0' || str[i] == '-')
	{
		ft_get_flags(str, i, format);
		i++;
		result++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (ft_isdigit(str[i]))
		{
			format->width = ft_atoi(ft_substr(str, i, 10));
			i += ft_strlen(ft_itoa(format->width));
			result += ft_strlen(ft_itoa(format->width));
		}
		else
			format->width = va_arg(*vl, int);
	}
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
		{
			format->precision = ft_atoi(ft_substr(str, i, 10));
			i += ft_strlen(ft_itoa(format->precision));
			result += ft_strlen(ft_itoa(format->precision));
		}
		else if (str[i] == '*')
			format->precision = va_arg(*vl, int);
		else
			ft_error();
	}
	if (ft_strchr("scpdiux%X", str[i]))
		format->specifier = str[i];
	result++;
	return (result);
	/*else
		ft_error();*/
}

size_t	ft_get_length(char *str_from_arg, t_format *format)
{
	size_t res_length;

	res_length = 0;
	if (format->specifier == 's')
		res_length = ft_get_string_length(str_from_arg, format);
	else if (format->specifier == 'c' || format->specifier == '%')
		res_length = ft_get_char_length(format);
	else if (format->specifier == 'p')
		res_length = ft_get_pointer_length(format);
	else if (format->specifier == 'd' || format->specifier == 'i')
		res_length = ft_get_integer_length(str_from_arg, format);
	else if (format->specifier == 'u' || format->specifier == 'x'
			|| format->specifier == 'X')
		res_length = ft_get_unsigned_length(str_from_arg, format);
	return (res_length);
}

size_t ft_get_string_length(char *str_from_arg, t_format *format)
{
	size_t res_length;

	res_length = ft_strlen(str_from_arg);
	if (format->precision > res_length)
		res_length = format->precision;
	else if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

size_t ft_get_char_length(t_format *format)
{
	size_t res_length;

	res_length = 1;
	if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

size_t	ft_get_pointer_length(t_format *format)
{
	size_t res_length;

	res_length = 12; //una dirección de memoria creo que siempre mide lo mismo: 12 + 2 por el 0x
	if (format->precision > res_length)
		res_length = format->precision;
	else if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

size_t	ft_get_integer_length(char *str_from_arg, t_format *format)
{
	size_t length;

	length = ft_strlen(str_from_arg);
	if (format->precision < length)
		format->precision = length;
	if (format->precision >= format->width)
	{
		if (str_from_arg[0] == '-')
			length = format->precision + 1;
		else
			length = format->precision;
	}
	else if (format->width > length)
		length = format->width;
	return (length);
}

size_t	ft_get_unsigned_length(char *str_from_arg, t_format *format)
{
	size_t length;

	length = ft_strlen(str_from_arg);
	if (format->precision < length)
		format->precision = length;
	if (format->precision >= format->width)
		length = format->precision;
	else if (format->width > length)
		length = format->width;
	return (length);
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

void	ft_putnchar(char c, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

void ft_print_string(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (lengths->res_length <= lengths->arg_length)
		write(1, str_from_arg, lengths->res_length);
	else
	{
		if (format->flag_minus == 1)
		{
			write(1, str_from_arg, lengths->arg_length);
			ft_putnchar(' ', lengths->res_length - lengths->arg_length);
		}
		else
		{
			if (format->flag_zero == 1)
			{
				ft_putnchar('0', lengths->res_length - lengths->arg_length);
				write(1, str_from_arg, lengths->arg_length);
			}
			else
			{
				ft_putnchar(' ', lengths->res_length - lengths->arg_length);
				write(1, str_from_arg, lengths->arg_length);
			}
		}
	}
}

void ft_print_char(char *str_from_arg, t_format *format, t_lengths *lengths)
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

void ft_print_pointer(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (lengths->res_length == lengths->arg_length)
		write(1, str_from_arg, lengths->res_length);
	else if (format->flag_minus)
	{
		print_address(format, lengths, str_from_arg);
		ft_putnchar(' ', lengths->res_length - format->precision - lengths->arg_length);
	}
	else if (format->flag_zero)
	{
		ft_putnchar('0', lengths->res_length - format->precision - lengths->arg_length);
		print_address(format, lengths, str_from_arg);
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - format->precision - lengths->arg_length);
		print_address(format, lengths, str_from_arg);
	}
}

void	print_address(t_format *format, t_lengths *lengths, char *str)
{
	write(1, "0x", 2);
	ft_putnchar('0', lengths->res_length - format->precision);
	write (1, str, lengths->res_length);
}

char	*ft_itoa_hex(unsigned long long n)
{
	char	*str;
	int		length;
	int		remainder;

	length = itoa_hex_length(n);
	if (!(str = (char *)malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	while (n != 0)
	{
		remainder = n % 16;
		if (remainder > 9)
			str[length-- - 1] = (remainder - 10) + 'a';
		else
			str[length-- - 1] = remainder + '0';
		n = n / 16;
	}
	return (str);
}

int	itoa_hex_length(unsigned long long int n)
{
	int length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		length++;
		n = n / 16;
	}
	return (length);
}

void	ft_print_integer(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (str_from_arg[0] == '-')
		ft_print_negative(str_from_arg, format, lengths);
	else
	{
		if (format->precision < lengths->arg_length)
			format->precision = lengths->arg_length;
		if ((size_t)lengths->res_length == lengths->arg_length)
			write(1, str_from_arg, lengths->arg_length);
		else if (format->precision >= format->width)
		{
			ft_putnchar('0', format->precision - lengths->arg_length);
			write(1, str_from_arg, lengths->arg_length);
		}
		else if (format->flag_minus)
		{
			ft_putnchar('0', format->precision - lengths->arg_length);
			write(1, str_from_arg, lengths->arg_length);
			ft_putnchar(' ', lengths->res_length - format->precision);
		}
		else if (format->precision > lengths->arg_length && format->flag_zero)
		{
			ft_putnchar(' ', lengths->res_length - format->precision);
			ft_putnchar('0', format->precision - lengths->arg_length);
			write(1, str_from_arg, lengths->arg_length);
		}
		else
		{
			ft_putnchar(' ', lengths->res_length - format->precision);
			ft_putnchar('0', format->precision - lengths->arg_length);
			write(1, str_from_arg, lengths->arg_length);
		}
	}
}

void	ft_print_negative(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (format->precision < lengths->arg_length - 1)
		format->precision = lengths->arg_length;
	if ((size_t)lengths->res_length == lengths->arg_length)
		write(1, str_from_arg, lengths->arg_length);
	else if (format->precision >= format->width)
	{
		write(1, "-", 1);
		ft_putnchar('0', format->precision - lengths->arg_length + 1);
		char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
		write(1, substr, lengths->arg_length);
	}
	else if (format->flag_minus)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
		ft_putnchar(' ', lengths->res_length - format->precision);
	}
	else if (format->precision > lengths->arg_length && format->flag_zero)
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
}

void ft_print_unsigned(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (format->precision < lengths->arg_length)
		format->precision = lengths->arg_length;
	if ((size_t)lengths->res_length == lengths->arg_length)
		write(1, str_from_arg, lengths->arg_length);
	else if (format->precision >= format->width)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
	else if (format->flag_minus)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
		ft_putnchar(' ', lengths->res_length - format->precision);
	}
	else if (format->precision > lengths->arg_length && format->flag_zero)
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
}

void ft_print_hex(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (format->precision < lengths->arg_length)
		format->precision = lengths->arg_length;
	if ((size_t)lengths->res_length == lengths->arg_length)
		write(1, str_from_arg, lengths->arg_length);
	else if (format->precision >= format->width)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
	else if (format->flag_minus)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
		ft_putnchar(' ', lengths->res_length - format->precision);
	}
	else if (format->precision > lengths->arg_length && format->flag_zero)
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		write(1, str_from_arg, lengths->arg_length);
	}
}

void	ft_error()
{
	ft_putstr_fd("An error occured", 1);
}

