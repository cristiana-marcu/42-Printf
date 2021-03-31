/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:49:48 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 19:12:44 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_f_prec(t_format *format, char *str, int i, int *p_result)
{
	while (str[i] == '0')
	{
		*p_result += 1;
		i += 1;
	}
	if (ft_isdigit(str[i]))
		format->precision = ft_atoi(str + i);
	else
		format->precision = 0;
	if (format->precision != 0)
		i += integer_length(format->precision);
	else
		*p_result -= 1;
	*p_result += integer_length(format->precision) + 1;
	return (i);
}

int	check_f_prec_vl(t_format *format, va_list *vl, int i, int *p_result)
{
	format->precision = va_arg(*vl, int);
	i += 1;
	*p_result += 2;
	return (i);
}

void	check_f_prec_not(t_format *format, int *p_result)
{
	format->precision = 0;
	*p_result += 1;
}
