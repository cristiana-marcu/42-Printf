/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:48:31 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:50:17 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_formatters(va_list *vl, char *str, int i, t_format *format)
{
	int	result;
	int	*p_result;

	result = 1;
	p_result = &result;
	i++;
	while (str[i] == '0' || str[i] == '-')
		i = check_f_flags(format, str, i, p_result);
	if (ft_isdigit(str[i]))
		i = check_f_width(format, str, i, p_result);
	else if (str[i] == '*')
		i = check_f_width_vl(format, vl, i, p_result);
	if (str[i] == '.')
	{
		i++;
		if (ft_isdigit(str[i]))
			i = check_f_prec(format, str, i, p_result);
		else if (str[i] == '*')
			i = check_f_prec_vl(format, vl, i, p_result);
		else
			check_f_prec_not(format, p_result);
		format->p_has_changed = 1;
	}
	check_specifier(str, i, format);
	return (++result);
}

void	ft_get_flags(char *str, int i, t_format *format)
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

int	check_f_flags(t_format *format, char *str, int i, int *p_result)
{
	ft_get_flags(str, i, format);
	i += 1;
	*p_result += 1;
	return (i);
}

void	check_specifier(char *str, int i, t_format *format)
{
	if (ft_strchr("scpdiux%X", str[i]))
		format->specifier = str[i];
}
