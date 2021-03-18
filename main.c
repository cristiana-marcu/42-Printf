/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/18 17:54:58 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main()
{
	//static char	a01;
	//static char	a02;
	//static char *s_hidden = "hi low\0don't print me lol\0";
	//char *mystring = "nono";
	//char mychar = '%';
	//int mynumber = -120;
	ft_printf("-----------Mine--------------\n");
	//ft_printf("Char: %c", mychar);
	//ft_printf("\n");
	///ft_printf("String: %s", mystring);
	//ft_printf("\n");
	//ft_printf("Chars: %c", '1');
	//ft_printf("Pointer: %-32p%-32p", &a01, &a02);
	ft_printf("hello, %5.0uhi", 0);
	ft_printf("\n");
	ft_printf("-----------Official----------\n");
	//printf("Char: %c", mychar);
	//ft_printf("\n");
	//printf("String: %s", mystring);
	//printf("\n");
	//printf("Pointer: %-32p%-32p", &a01, &a02);
	printf("hello, %5.0uhi", 0);
	printf("\n");
}
