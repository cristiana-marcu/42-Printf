/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:42:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/02/16 13:44:44 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(char *str, ...)
{
	va_list vl;
	int		printed;
	void	*argument;

	va_start(vl, str);
	printed = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
			{
				argument = (char *)argument;
				argument = va_arg(vl, char *);
				write(1, argument, ft_strlen(argument));
				printed = printed + ft_strlen(argument);
			}
			else if (*str == 'c')
			{
				argument = (char *)argument;
				argument = va_arg(vl, char *);
				ft_putchar_fd(*str, 0);
				printed++;
			}
			else if (*str == 'd' || *str == 'i')
			{
				argument = (int*)argument;
				argument = va_arg(vl, int*);
				ft_putnbr_fd((int)argument, 0);
				printed += 14;
			}
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
			printed++;
		}
	}
	return (printed);
}
