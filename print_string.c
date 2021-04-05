/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:52:40 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/05 17:56:20 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_string(char *str_from_arg, t_format *format,
t_lengths *lengths)
{
	char	*temp;
	size_t	strlen;

	if ((format->precision < format->width && format->p_has_changed)
		|| lengths->res_length < lengths->arg_length)
	{
		printf("hellooooooo %s\n", str_from_arg);
		temp = ft_substr(str_from_arg, 0, (size_t)format->precision);
		str_from_arg = temp;
		//free(temp);
	}
	strlen = ft_strlen(str_from_arg);
	if (format->flag_minus)
		ft_putstr_fd(str_from_arg, 1);
	ft_putnchar(' ', format->width - strlen);
	if (!format->flag_minus)
		ft_putstr_fd(str_from_arg, 1);
}
