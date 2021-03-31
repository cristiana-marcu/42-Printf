/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:58:34 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 19:11:51 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(char *str_from_arg, t_format *format,
t_lengths *lengths)
{
	int	diff;

	diff = get_diff(format, lengths);
	ft_print_positive(str_from_arg, format, lengths, diff);
}

void	ft_print_hex(char *str_from_arg, t_format *format, t_lengths *lengths)
{
	int	diff;

	diff = get_diff(format, lengths);
	ft_print_positive(str_from_arg, format, lengths, diff);
}
