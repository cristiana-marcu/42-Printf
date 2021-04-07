/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_string2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:00:37 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/07 12:51:16 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_handle_u(va_list *vl)
{
	char				*str;
	unsigned int		arg;

	arg = va_arg(*vl, unsigned int);
	str = ft_itoa(arg);
	return (str);
}

char	*ft_handle_x(va_list *vl)
{
	char				*str;
	char				*temp;
	unsigned int		arg;

	arg = va_arg(*vl, unsigned int);
	if (arg == 0)
	{
		temp = (char *)malloc(sizeof(char) * 2);
		if (!temp)
			return (NULL);
		temp[0] = '0';
		temp[1] = '\0';
	}
	else
		temp = ft_itoa_base(arg, 16);
	str = temp;
	return (str);
}

char	*ft_handle_X(va_list *vl)
{
	char				*str;
	char				*temp;
	unsigned int		arg;

	arg = va_arg(*vl, unsigned int);
	if (arg == 0)
	{
		temp = (char *)malloc(sizeof(char) * 2);
		if (!temp)
			return (NULL);
		temp[0] = '0';
		temp[1] = '\0';
	}
	else
		temp = ft_itoa_base(arg, 16);
	str = ft_strtoupper(temp);
	return (str);
}

int	ft_math_abs(int precision)
{
	return (precision * -1);
}
