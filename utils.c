/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 18:41:24 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/31 18:47:55 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strtoupper(char *str_from_arg)
{
	int	i;

	i = 0;
	while (str_from_arg[i] != '\0')
	{
		if (ft_isalpha(str_from_arg[i]))
			str_from_arg[i] = ft_toupper(str_from_arg[i]);
		i++;
	}
	return (str_from_arg);
}

int	integer_length(int n)
{
	int	length;

	length = 0;
	if (n < 0)
		length++;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

void	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return ;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}

char	*ft_itoa_base(unsigned long long n, unsigned long long base)
{
	char	*str;
	int		length;
	int		remainder;

	length = itoa_base_length(n, base);
	str = (char *)malloc(sizeof(*str) * (length + 1));
	if (!str)
		return (NULL);
	str[length] = '\0';
	while (n != 0)
	{
		remainder = n % base;
		if (remainder > 9)
			str[length-- - 1] = (remainder - 10) + 'a';
		else
			str[length-- - 1] = remainder + '0';
		n = n / base;
	}
	return (str);
}

int	itoa_base_length(unsigned long long n, unsigned long long base)
{
	int	length;

	length = 0;
	if (n == 0)
		length = 1;
	while (n != 0)
	{
		length++;
		n = n / base;
	}
	return (length);
}
