/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:42:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/02/17 14:20:19 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printf(char *str, ...)
{
	va_list vl;
	int		printed;
	void	*argu;

	va_start(vl, str);
	printed = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 's')
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
