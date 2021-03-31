/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:50:39 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:50:51 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_f_width(t_format *format, char *str, int i, int *p_result)
{
	format->width = ft_atoi(str + i);
	i += integer_length(format->width);
	*p_result += integer_length(format->width);
	return (i);
}

int	check_f_width_vl(t_format *format, va_list *vl, int i, int *p_result)
{
	format->width = va_arg(*vl, int);
	i += 1;
	*p_result += 1;
	return (i);
}
