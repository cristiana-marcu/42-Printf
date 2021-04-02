/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/02 17:30:55 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int	main()
{
	//static char	a01;
	//static char	a02;
	//static char *s_hidden = "hi low\0don't print me lol\0";
	//char *mystring = "nono";
	//char mychar = '%';
	//int mynumber = -120;

	int		mine;
	int		official;
	mine = ft_printf(" %10p %-10p| ", 0, 0);
	printf("\n");
	official = printf(" %10p %-10p| ", 0, 0);
	printf("\n");
	ft_printf("My length: %d", mine);
	printf("\n");
	printf("Her length: %d", official);
	printf("\n");


	//static unsigned int		mx_u = 236;
	//static char				mx_c = 'G';
	//static char			   *mx_s = "Hello, World!";
	//static int				mx_i = 42;


	// ft_printf("Mine: %.3u", 13862);
	// printf("\n");
	// printf("Hers: %.3u", 13862);
	// printf("\n");

	//ft_printf("-----------Mine--------------\n");
	// //ft_printf("Char: %5%");
	// //ft_printf("\n");
	// ft_printf("String: %.6i", -3);
	// ft_printf("\n");
	// // //ft_printf("Chars: %c", '1');
	//ft_printf("|%-4.*d|<--\n", 4, -135);
	// // ft_printf("Pointer: %5.p", NULL);
	///ft_printf("\n");
	//ft_printf("-----------Official----------\n");
	// // // printf("Char: %5%");
	// //ft_printf("\n");
	// printf("String: %.6i", -3);
	// printf("\n");
	///printf("|%-4.*d|<--\n", 4, -135);
	// // //printf("hello, %5p", 0);
	// // printf("\n");

	/*int		i;
	int		j;
	i = printf("ft: jaja[%30.10s] [%.3s] [%.30s] [%20s] [%30.10d] [%30d %.10d] [%30.10d] [%5.0d] [%30.10x] [%30x] [%.10x] [%30.10x] [%5.0x]\n", "jaime que", "jaime", "jaime", "jaime", 30, 30 , 303030, -303030, 0, 30, 30 , 303030, -303030, 0);
	printf("ft: %d\n", i);
	i = ft_printf("sy: jaja[%30.10s] [%.3s] [%.30s] [%20s] [%30.10d] [%30d %.10d] [%30.10d] [%5.0d] [%30.10x] [%30x] [%.10x] [%30.10x] [%5.0x]\n", "jaime que", "jaime", "jaime", "jaime", 30, 30 , 303030, -303030, 0, 30, 30 , 303030, -303030, 0);
	printf("sy: %d\n", i);
	i = printf("[%6ld], [%10.3s]\n", -2147483648, "");
	printf("ft: %d\n", i);
	j = ft_printf("[%6d], [%10.3s]\n", -2147483648, "");
	printf("sy: %d\n", j);*/
}


/*void check(int a, int b, int c)
{
	printf("\n\t[ft_printf= %d\tprintf = %d]", a, b);
	printf("\tTEST %d", c);
	if (a != b)
		printf(" => ERROR %d != %d\n\n", a, b);
	else
		printf(" => OK\n\n");
	printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
}*/


