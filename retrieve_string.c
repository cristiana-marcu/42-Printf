/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:00:02 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/07 12:45:08 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_arg_to_string(va_list *vl, t_format *format)
{
	char				*str_from_arg;

	if (format->specifier == 's')
		str_from_arg = ft_handle_s(vl);
	else if (format->specifier == 'c')
		str_from_arg = ft_handle_c(vl);
	else if (format->specifier == '%')
		str_from_arg = ft_strdup("%");
	else if (format->specifier == 'p')
		str_from_arg = ft_handle_p(vl);
	else if (format->specifier == 'd' || format->specifier == 'i')
		str_from_arg = ft_handle_di(vl);
	else if (format->specifier == 'u')
		str_from_arg = ft_handle_u(vl);
	else if (format->specifier == 'x')
		str_from_arg = ft_handle_x(vl);
	else if (format->specifier == 'X')
		str_from_arg = ft_handle_X(vl);
	else
		str_from_arg = ft_strdup("");
	return (str_from_arg);
}

char	*ft_handle_c(va_list *vl)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = va_arg(*vl, int);
	str[1] = '\0';
	return (str);
}

char	*ft_handle_s(va_list *vl)
{
	char	*str;

	str = va_arg(*vl, char *);
	if (str == NULL || str == 0)
		str = "(null)";
	return (ft_strdup(str));
}

char	*ft_handle_p(va_list *vl)
{
	char				*str;
	unsigned long long	arg;

	arg = (unsigned long long)va_arg(*vl, void *);
	str = ft_itoa_base(arg, 16);
	return (str);
}

char	*ft_handle_di(va_list *vl)
{
	char				*str;
	unsigned long long	arg;

	arg = (long long)va_arg(*vl, int);
	str = ft_itoa(arg);
	return (str);
}
