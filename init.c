/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:51:21 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:51:30 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_format(t_format *format)
{
	format->flag_minus = 0;
	format->flag_zero = 0;
	format->width = 0;
	format->precision = 1;
	format->specifier = '\0';
	format->p_has_changed = 0;
}

void	ft_init_lengths(t_lengths *lengths, char *str_from_arg,
t_format *format)
{
	lengths->arg_length = (int)ft_strlen(str_from_arg);
	lengths->res_length = ft_get_length(str_from_arg, format);
}
