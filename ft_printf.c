/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:42:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/19 15:44:59 by cmarcu           ###   ########.fr       */
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
			ft_init_lengths(&lengths, str_from_arg, &format);
			ft_print_arg(str_from_arg, &format, &lengths);
			//i++;
		}
		if (str[i] != '\0' && str[i] != '%')
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
	unsigned long long		arg;

	if (format->specifier == 's')
	{
		str_from_arg = va_arg(*vl, char *);
		if (str_from_arg == NULL || str_from_arg == 0)
			str_from_arg = "(null)";
	}
	else if (format->specifier == 'c')
		str_from_arg = ft_handle_chars(vl);
	else if (format->specifier == '%')
		str_from_arg = "%";
	else if (format->specifier == 'p')
	{
		arg = (unsigned long long)va_arg(*vl, void *);
		str_from_arg = ft_itoa_base(arg, 16);
	}
	else if (format->specifier == 'd' || format->specifier == 'i')
		str_from_arg = ft_itoa(va_arg(*vl, int));
	else if (format->specifier == 'u')
		str_from_arg = ft_itoa_base(va_arg(*vl, unsigned int), 10);
	else if (format->specifier == 'x')
		str_from_arg = ft_itoa_base(va_arg(*vl, unsigned int), 16);
	else if (format->specifier == 'X')
		str_from_arg = ft_strtoupper(ft_itoa_base(va_arg(*vl, unsigned int), 16));
	else
		str_from_arg = "";
	return (str_from_arg);
}

char	*ft_strtoupper(char *str_from_arg)
{
	int i;

	i = 0;
	while (str_from_arg[i] != '\0')
	{
		if (ft_isalpha(str_from_arg[i]))
			str_from_arg[i] = ft_toupper(str_from_arg[i]);
		i++;
	}
	return (str_from_arg);
}

char	*ft_handle_chars(va_list *vl)
{
	char *str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = va_arg(*vl, int);
	str[1] = '\0';
	return (str);
}

void ft_init_format(t_format *format)
{
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->width = 0;
	format->precision = 1;
	format->specifier = '\0';
	format->p_has_changed = 0;
}

void	ft_init_lengths(t_lengths *lengths, char *str_from_arg, t_format *format)
{
	lengths->arg_length = (int)ft_strlen(str_from_arg);
	lengths->res_length = ft_get_length(str_from_arg, format);
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
		{
			format->width = va_arg(*vl, int);
			i++;
			result++;
		}
	}
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
		{
			if (str[i] == '0' && !ft_isdigit(str[i + 1]))
			{
				format->precision = 0;
				i++;
			}
			else
				format->precision = ft_atoi(ft_substr(str, i, 10));
			while (str[i] == '0')
			{
				result++;
				i++;
			}
			if (format->precision != 0)
				i += ft_strlen(ft_itoa(format->precision));
			result += ft_strlen(ft_itoa(format->precision)) + 1;
		}
		else if (str[i] == '*')
		{
			format->precision = va_arg(*vl, int);
			i++;
			result += 2;
		}
		else
		{
			format->precision = 0;
			result++;
		}
		format->p_has_changed = 1;
	}
	if (ft_strchr("scpdiux%X", str[i]))
		format->specifier = str[i];
	result++;
	return (result);
}

int	ft_get_length(char *str_from_arg, t_format *format)
{
	int res_length;

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

int ft_get_string_length(char *str_from_arg, t_format *format)
{
	int res_length;

	res_length = ft_strlen(str_from_arg);
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width *= -1;
	}
	if (format->precision < 0)
		format->precision = res_length;
	if (format->width > format->precision && format->width > res_length && format->precision >= res_length)
		res_length = format->width;
	else if (format->precision < res_length && res_length != 0 && format->p_has_changed)
		res_length = format->precision;
	else if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

int ft_get_char_length(t_format *format)
{
	int res_length;

	res_length = 1;
	if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

int	ft_get_pointer_length(t_format *format, char *str_from_arg)
{
	int res_length;

	res_length = ft_strlen(str_from_arg) + 2;
	if (res_length == 2)
		res_length = 3;
	if (format->precision > res_length)
		res_length = format->precision + 2;
	else if (format->width > res_length)
		res_length = format->width;
	return (res_length);
}

int	ft_get_integer_length(char *str_from_arg, t_format *format)
{
	int length;

	length = ft_strlen(str_from_arg);
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width *= -1;
	}
	if (format->precision == 0)
		format->precision = 0;
	else if (format->precision < length)
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

int	ft_get_unsigned_length(char *str_from_arg, t_format *format)
{
	int length;

	length = ft_strlen(str_from_arg);
	if (format->precision < 0)
		length = 1;
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

void	ft_putnchar(char c, int n)
{
	int i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

void ft_print_string(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (lengths->res_length < lengths->arg_length)
		str_from_arg = ft_substr(str_from_arg, 0, (size_t)format->precision);
	if (lengths->res_length <= lengths->arg_length && format->width <= lengths->res_length)
		ft_putstr_fd(str_from_arg, 1);
	else if (format->flag_minus == 1)
	{
		ft_putstr_fd(str_from_arg, 1);
		if (lengths->arg_length > lengths->res_length)
			ft_putnchar(' ', format->width - format->precision);
		else
			ft_putnchar(' ', lengths->res_length - lengths->arg_length);
	}
	else if (format->flag_zero)
	{
		ft_putnchar('0', lengths->res_length - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
	else if (format->width > format->precision && lengths->arg_length > lengths->res_length)
	{
		ft_putnchar(' ', format->width - format->precision);
		ft_putstr_fd(str_from_arg, 1);
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
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
	if (str_from_arg == NULL)
		write(1, "0x0", 3);
	if (lengths->res_length == lengths->arg_length)
		ft_putstr_fd(str_from_arg, 1);
	else if (format->flag_minus)
	{
		print_address(format, lengths, str_from_arg);
		ft_putnchar(' ', lengths->res_length - lengths->arg_length - 2);
	}
	else if (format->flag_zero)
	{
		ft_putnchar('0', lengths->res_length - format->precision - lengths->arg_length);
		print_address(format, lengths, str_from_arg);
	}
	else
	{
		if (format->width > lengths->arg_length && lengths->arg_length != 0)
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
	else if (lengths->res_length == 3 || str[0] == '\0')
		write(1, "0", 1);
	ft_putstr_fd(str, 1);
}

char	*ft_itoa_base(unsigned long long n, unsigned long long base)
{
	char	*str;
	int		length;
	int		remainder;

	length = itoa_base_length(n, base);
	if (!(str = (char *)malloc(sizeof(*str) * (length + 1))))
		return (NULL);
	while (n != 0)
	{
		remainder = n % base;
		if (remainder > 9)
			str[length-- - 1] = (remainder - 10) + 'a';
		else
			str[length-- - 1] = remainder + '0';
		n = n / base;
	}
	return (str);
}

int	itoa_base_length(unsigned long long n, unsigned long long base)
{
	int length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		length++;
		n = n / base;
	}
	return (length);
}

void	ft_print_integer(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (str_from_arg[0] == '-')
		ft_print_negative(str_from_arg, format, lengths);
	else
	{
		/*if (format->precision < lengths->arg_length)
			format->precision = lengths->arg_length;*/
		if (lengths->res_length == lengths->arg_length)
			ft_putstr_fd(str_from_arg, 1);
		else if (format->precision == 0)
			ft_putnchar(' ', lengths->res_length);
		else if (format->precision >= format->width)
		{
			ft_putnchar('0', format->precision - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
		}
		else if (format->flag_minus)
		{
			ft_putnchar('0', format->precision - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
			ft_putnchar(' ', lengths->res_length - format->precision);
		}
		else if (format->precision > lengths->arg_length && format->flag_zero)
		{
			ft_putnchar(' ', lengths->res_length - format->precision);
			ft_putnchar('0', format->precision - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
		}
		else if (format->width > lengths->arg_length && format->flag_zero)
		{
			if (format->precision <= lengths->arg_length && format->p_has_changed)
			{
				ft_putnchar(' ', format->width - lengths->arg_length);
				ft_putstr_fd(str_from_arg, 1);
			}
			else
			{
				ft_putnchar('0', format->width - lengths->arg_length);
				ft_putstr_fd(str_from_arg, 1);
			}
		}
		else
		{
			ft_putnchar(' ', lengths->res_length - format->precision);
			ft_putnchar('0', format->precision - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
		}
	}
}

void	ft_print_negative(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (format->precision < lengths->arg_length - 1 && format->precision >= format->width)
		format->precision = lengths->arg_length;
	if (format->precision == lengths->arg_length + 1 && format->precision < format->width)
		format->precision = lengths->arg_length + 1;
	if (lengths->res_length == lengths->arg_length)
		write(1, str_from_arg, lengths->arg_length);
	else if ((format->precision == lengths->arg_length && format->width < format->precision) || format->width == lengths->arg_length)
		write(1, str_from_arg, lengths->arg_length);
	else if (format->precision > format->width)
	{
		write(1, "-", 1);
		ft_putnchar('0', format->precision - lengths->arg_length + 1);
		char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
		ft_putstr_fd(substr, 1);
	}
	else if (format->flag_minus)
	{
		write(1, "-", 1);
		if (format->precision > lengths->arg_length)
			ft_putnchar('0', format->precision - lengths->arg_length + 1);
		char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
		ft_putstr_fd(substr, 1);
		if (format->precision > lengths->arg_length)
			ft_putnchar(' ', lengths->res_length - format->precision - 1);
		else
			ft_putnchar(' ', lengths->res_length - format->precision);
	}
	else if (format->precision > lengths->arg_length && format->flag_zero)
	{
		ft_putnchar(' ', lengths->res_length - format->precision - 1);
		write(1, "-", 1);
		ft_putnchar('0', format->precision - lengths->arg_length + 1);
		char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
		ft_putstr_fd(substr, 1);
	}
	else if (format->width > format->precision && format->p_has_changed && format->precision > lengths->arg_length)
	{
		ft_putnchar(' ', lengths->res_length - format->precision - 1);
		write(1, "-", 1);
		ft_putnchar('0', format->precision - lengths->arg_length + 1);
		char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
		ft_putstr_fd(substr, 1);
	}
	else if (format->width > lengths->arg_length && format->flag_zero)
	{
		if (format->precision < format->width && format->p_has_changed)
		{
			ft_putnchar(' ', lengths->res_length - format->precision);
			write(1, "-", 1);
			ft_putnchar('0', format->precision - lengths->arg_length);
			char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
			ft_putstr_fd(substr, 1);
		}
		else
		{
			write(1, "-", 1);
			ft_putnchar('0', format->width - lengths->arg_length);
			char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
			ft_putstr_fd(substr, 1);
		}
	}
	else if (format->width > format->precision && format->precision > lengths->arg_length)
	{
		ft_putnchar(' ', lengths->res_length - format->precision - 1);
		write(1, "-", 1);
		ft_putnchar('0', format->precision - lengths->arg_length + 1);
		char *substr = ft_substr(str_from_arg, 1, lengths->arg_length - 1);
		ft_putstr_fd(substr, 1);
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
}

void ft_print_unsigned(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (lengths->res_length == lengths->arg_length)
			ft_putstr_fd(str_from_arg, 1);
	else if (format->precision == 0)
		ft_putnchar(' ', lengths->res_length);
	else if (format->precision >= format->width)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
	else if (format->flag_minus)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
		ft_putnchar(' ', lengths->res_length - format->precision);
	}
	else if (format->precision > lengths->arg_length && format->flag_zero && format->p_has_changed)
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
	else if (format->width > lengths->arg_length && format->flag_zero)
	{
		if (format->precision <= lengths->arg_length && format->p_has_changed)
		{
			ft_putnchar(' ', format->width - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
		}
		else
		{
			ft_putnchar('0', format->width - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
		}
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
}

void ft_print_hex(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	if (format->precision < lengths->arg_length)
		format->precision = lengths->arg_length;
	if (lengths->res_length == lengths->arg_length)
			ft_putstr_fd(str_from_arg, 1);
	else if (format->precision == 0)
		ft_putnchar(' ', lengths->res_length);
	else if (format->precision >= format->width)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
	else if (format->flag_minus)
	{
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
		ft_putnchar(' ', lengths->res_length - format->precision);
	}
	else if (format->precision > lengths->arg_length && format->flag_zero && format->p_has_changed)
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
	else if (format->width > lengths->arg_length && format->flag_zero)
	{
		if (format->precision <= lengths->arg_length && format->p_has_changed)
		{
			ft_putnchar(' ', format->width - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
		}
		else
		{
			ft_putnchar('0', format->width - lengths->arg_length);
			ft_putstr_fd(str_from_arg, 1);
		}
	}
	else
	{
		ft_putnchar(' ', lengths->res_length - format->precision);
		ft_putnchar('0', format->precision - lengths->arg_length);
		ft_putstr_fd(str_from_arg, 1);
	}
}

void	ft_error()
{
	ft_putstr_fd("An error occured", 1);
}
