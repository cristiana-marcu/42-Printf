/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:42:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/04 13:29:11 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_printf(char *str, ...)
{
	va_list vl;
	int		i;
	t_format format;
	size_t	res_length;

	va_start(vl, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_format(&format);
			ft_check_formatters(vl, str, i, &format);
			res_length = ft_get_length(vl, &format);
			ft_print_arg(vl, str, res_length);
		}
		write(1, &str[i], 1);
		i++;
	}
	return (i);
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

void ft_check_formatters(va_list vl, char *str, int i, t_format *format)
{
	i++;
	while (str[i++] == '0' || str[i++] == '-')
		ft_get_flags(str, i, format);
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (ft_isdigit(str[i]))
			format->width = ft_atoi(str);
			//mover i tantos dígitos como tenga el resultado del atoi
		else
			format->width = va_arg(vl, char *);
	}
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
			format->precision = ft_atoi(str);
			//mover i tantos dígitos como tenga el resultado del atoi
		else if (str[i] == '*')
			format->precision = va_arg(vl, char *);
		else
			ft_error();
	}
	if (ft_strchr("scpdiuxX%", str[i]))
		format->specifier = str[i];
	else
		ft_error();
}

size_t	ft_get_length(va_list vl, t_format *format)
{
	size_t res_length;

	if (format->specifier == 's')
		res_length = ft_get_string_length(vl, &format);
	else if (format->specifier == 'c' || format->specifier == '%')
		res_length = ft_get_char_length(&format);
	else if (format->specifier == 'p')
		res_length = ft_get_pointer_length(&format);
	else if (format->specifier == 'd' || format->specifier == 'i')
		res_length = ft_get_integer_length(vl, &format);
	else if (format->specifier == 'u' || format->specifier == 'x'
			|| format->specifier == 'X')
		res_length = ft_get_unsigned_length(vl, &format);
	return (res_length);
}

size_t ft_get_string_length(va_list vl, t_format *format)
{
	size_t res_length;

	res_length = ft_strlen(va_arg(vl, char *));
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

	res_length = 14; //una dirección de memoria creo que siempre mide lo mismo: 12 + 2 por el 0x
	if (format->precision > res_length)
		res_length = format->precision;
	else if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

size_t	ft_number_length(int n)
{
	size_t length;

	length = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

size_t	ft_get_integer_length(va_list vl, t_format *format)
{
	size_t length;
	int number;

	number = va_arg(vl, int);
	length = ft_number_length(number);
	if (format->precision < length)
		format->precision = length;
	if (format->precision >= format->width)
	{
		if (number < 0)
			length = format->precision + 1;
		else
			length = format->precision;
	}
	else if (format->width > length)
		length = format->width;
	return (length);
}

size_t	ft_unsigned_number_length(unsigned int n)
{
	size_t length;

	length = 0;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

size_t	ft_get_unsigned_length(va_list vl, t_format *format)
{
	size_t length;
	unsigned int number;

	number = va_arg(vl, unsigned int);
	length = ft_unsigned_number_length(number);
	if (format->precision < length)
		format->precision = length;
	if (format->precision >= format->width)
		length = format->precision;
	else if (format->width > length)
		length = format->width;
	return (length);
}

void	ft_print_arg(va_list vl, t_format *format, size_t res_length)
{
	if (format->specifier == 's')
		ft_print_string(vl, &format, res_length);
	else if (format->specifier == 'c' || format->specifier == '%')
		ft_print_char(vl, &format, res_length);
	else if (format->specifier == 'p')
		ft_print_pointer(vl, &format, res_length);
	else if (format->specifier == 'd' || format->specifier == 'i')
		ft_print_integer(vl, &format, res_length);
	else if (format->specifier == 'u')
		ft_print_unsigned(vl, &format, res_length);
	else if (format->specifier == 'x' || format->specifier == 'X')
		ft_print_hex(vl, &format, res_length);
}

void ft_print_string(va_list vl, t_format *format, size_t res_length)
{
	char	*toprint;
	size_t	arg_length;

	toprint = va_arg(vl, char *);
	arg_length = ft_strlen(toprint);
	if (res_length <= arg_length)
		write(1, &toprint, res_length);
	else
	{
		if (format->flag_minus == 1)
		{
			write(1, &toprint, arg_length);
			write(1, " ", res_length - arg_length);
		}
		else
		{
			if (format->flag_zero == 1)
			{
				write(1, "0", res_length - arg_length);
				write(1, &toprint, arg_length);
			}
			else
			{
				write(1, " ", res_length - arg_length);
				write(1, &toprint, arg_length);
			}
		}
	}
}

void ft_print_char(va_list vl, t_format *format, size_t res_length)
{
	char	toprint;

	toprint = va_arg(vl, char);
	if (res_length == 1)
		write(1, &toprint, 1);
	else
	{
		if (format->flag_minus == 1)
		{
			write(1, &toprint, 1);
			write(1, " ", res_length - 1);
		}
		else
		{
			if (format->flag_zero == 1)
			{
				write(1, "0", res_length - 1);
				write(1, &toprint, 1);
			}
			else
			{
				write(1, " ", res_length - 1);
				write(1, &toprint, 1);
			}
		}
	}
}

void ft_print_pointer(va_list vl, t_format *format, size_t res_length)
{
	void					*arg;
	unsigned long long int	toprint;
	char					*str;
	size_t					arg_length;

	arg = va_arg(vl, void *);
	toprint = &arg;
	str = ft_itoa_hex(toprint);
	arg_length = ft_strlen(str);
	if (res_length == arg_length)
		ft_putstr_fd(str, 1);
	else if (format->flag_minus)
	{
		print_address(&format, res_length, str);
		write (1, ' ', res_length - format->precision - arg_length);
	}
	else if (format->flag_zero)
	{
		write (1, '0', res_length - format->precision -  arg_length);
		print_address(&format, res_length, str);
	}
	else
	{
		write (1, ' ', res_length - format->precision -  arg_length);
		print_address(&format, res_length, str);
	}
}

void	print_address(t_format *format, size_t res_length, char *str)
{
	write(1, '0x', 2);
	write (1, '0', res_length - format->precision);
	write (1, &str, res_length);
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

static int	itoa_hex_length(unsigned long long int n)
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

/*if (*str == 's')
			{
				argu = (char *)argu;
				argu = va_arg(vl, char *);
				write(1, argu, ft_strlen(argu));
				printed = printed + ft_strlen(argu);
			}
			else if (*str == 'c')
			{
				argu = (char *)argu;
				argu = va_arg(vl, char *);
				ft_putchar_fd(argu, 0);
				printed++;
			}
			else if (*str == 'd' || *str == 'i')
			{
				argu = (int*)argu;
				argu = va_arg(vl, int*);
				ft_putnbr_fd((int)argu, 0);
				printed += 14;
			}
			else if (*str == 'p')
			{
				argu = (void *)argu;
				argu = va_arg(vl, void *);
				ft_putnbr_fd(&argu, 0);
				printed += 14;
			}*/
