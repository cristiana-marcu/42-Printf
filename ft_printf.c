/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:42:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/02/26 15:19:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	ft_printf(char *str, ...)
{
	va_list vl;
	int		i;
	t_format format;

	va_start(vl, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_init_format(&format);
			ft_check_formatters(vl, str, i, &format);
			ft_get_length(vl, str, i);
			ft_print_arg(vl, str, i);
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
			format->flag_zero == 0;
		format->flag_minus = 1;
		return ;
	}
	format->flag_zero = 1;
}

void ft_check_formatters(va_list vl, char *str, int i, t_format *format)
{
	i++;
	while (str[i] == '0' || str[i] == '-')
	{
		ft_get_flags(str, i, format);
		i++;
	}
	if (ft_isdigit(str[i]) || str[i] == '*')
	{
		if (ft_isdigit(str[i]))
			format->width = ft_atoi(str);
		else
			format->width = va_arg(vl, char *);
	}
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
			format->precision = ft_atoi(str);
		else
			format->precision = va_arg(vl, char *);
	}
	if (ft_strchr(str[i], "scpdiuxX%"))
		format->specifier = str[i];
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