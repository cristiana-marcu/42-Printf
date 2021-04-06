/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/06 19:26:50 by cmarcu           ###   ########.fr       */
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
	//int mynumber = 198;

	// static char	a01;
	// static unsigned char a02;
	// static short a03;
	// static unsigned short a04;
	// static int a05;
	// static unsigned int a06;
	// static long a07;
	// static unsigned long a08;
	// static long long a09;
	// static unsigned long long a10;
	// static char *a11;
	// static void *a12;
	int		mine;
	int		official;
	//mine = ft_printf("|%p|\n", NULL);
	// official = printf("|%p|\n", NULL);
	// ft_printf("My length: %d\n", mine);
	// printf("Her length: %d\n", official);

	// printf(" LENGTH printf    : %d\n", printf("|%p|", NULL));
	// ft_printf(" LENGTH ft_printf : %d\n", ft_printf("|%p|", NULL));

	// printf(" LENGTH printf    : %d\n", printf("|%p|", NULL));
	// ft_printf(" LENGTH ft_printf : %d\n", ft_printf("|%p|", NULL));

	// printf(" LENGTH printf    : %d\n", printf("|%p|", NULL));
	// ft_printf(" LENGTH ft_printf : %d\n", ft_printf("|%p|", NULL));

	// printf(" LENGTH printf    : %d\n", printf("|%p|", NULL));
	// ft_printf(" LENGTH ft_printf : %d\n", ft_printf("|%p|", NULL));

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	//int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	a = 3;
	b = 1;
	// mine = ft_printf("%.p|\n", NULL);
	// official = printf("%.p|\n", NULL);

	// mine = ft_printf("%*p, %*x\n", a, NULL, a, 0);
	// official = printf("%*p, %*x\n", a, NULL, a, 0);
	// ft_printf("My length: %d\n", mine);
	// printf("Her length: %d\n", official);

	ft_printf("%0*.*d, %0*.*d, %0*.*d\n", a, b, c, a, b, e, a, b, d);
	printf("%0*.*d, %0*.*d, %0*.*d\n", a, b, c, a, b, e, a, b, d);

	/*char *s = "asd";
	char **p = &s;*/

	/*ft_printf(" LENGTH ft_printf : %d\n", ft_printf("|%p|", p));
	printf(" LENGTH printf    : %d\n\n", printf("|%p|", p));

	ft_printf(" LENGTH ft_printf : %d\n", ft_printf("|%-.8p|", p));
	printf(" LENGTH printf    : %d\n\n", printf("|%-.8p|", p));

	ft_printf(" LENGTH ft_printf : %d\n", ft_printf("|%-.2p|", p));
	printf(" LENGTH printf    : %d\n\n", printf("|%-.2p|", p));*/
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


