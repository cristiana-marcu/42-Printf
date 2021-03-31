/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_string2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 19:00:37 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 19:00:46 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_handle_u(va_list *vl)
{
	char				*str;
	char				*temp;

	temp = ft_itoa(va_arg(*vl, unsigned int));
	str = temp;
	free(temp);
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
	free(temp);
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
	free(temp);
	return (str);
}
