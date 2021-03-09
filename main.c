/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/09 19:42:12 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main()
{
	char *mystring = "nono";
	char mychar = 'Z';
	int mynumber = -120;
	printf("-----------Mi resultado:----------\n");
	ft_printf("Char: %c", mychar);
	printf("\n");
	ft_printf("String: %s", mystring);
	printf("\n");
	ft_printf("Number: %i", mynumber);
	printf("\n");
	printf("-----------Su resultado:----------\n");
	printf("Char: %c", mychar);
	printf("\n");
	printf("String: %s", mystring);
	printf("\n");
	printf("Number: %i", mynumber);
	printf("\n");
}
