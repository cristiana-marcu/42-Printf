/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/12 18:43:05 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main()
{
	//char *mystring = "nono";
	//char mychar = '%';
	//int mynumber = -120;
	ft_printf("-----------Mine--------------\n");
	//ft_printf("Char: %c", mychar);
	//ft_printf("\n");
	///ft_printf("String: %s", mystring);
	//ft_printf("\n");
	ft_printf("Number: %7.*d", 8, -14);
	ft_printf("\n");
	ft_printf("-----------Official----------\n");
	//printf("Char: %c", mychar);
	//ft_printf("\n");
	//printf("String: %s", mystring);
	//printf("\n");
	printf("Number: %7.*d", 8, -14);
	printf("\n");
}
