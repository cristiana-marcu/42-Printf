/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/26 16:53:35 by cmarcu           ###   ########.fr       */
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

	// int		mine;
	// int		official;
	// mine = ft_printf("String:  %1s %1s ", "123", "4567");
	// printf("\n");
	// official = printf("String:  %1s %1s ", "123", "4567");
	// printf("\n");
	// ft_printf("My length: %d", mine);
	// printf("\n");
	// printf("Her length: %d", official);
	// printf("\n");


	//static unsigned int		mx_u = 236;
	//static char				mx_c = 'G';
	//static char			   *mx_s = "Hello, World!";
	//static int				mx_i = 42;

	ft_printf("%.*s", 3, "hello");
	printf("\n");
	printf("%.*s", 3, "hello");
	printf("\n");

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
}

int main(int argc, char **argv)
{
	char specifier = '\0';
	int a, b, c;
	int leaks = 0;

	if (argv[1])
		specifier = argv[1][0];
	printf("\n\nFirst line = ft_printf\nSecond line = printf\n\n");
	if (leaks)
		printf("\nLEAKS = ON\n");
	else
		printf("\nLEAKS = OFF\n");
	if (specifier == 'c' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    CHAR    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		a = ft_printf("[%c]\n", 'X', 'a');
		b = printf("[%c]\n", 'X', 'a');
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %c [%24c]]\n", 'X', 'a');
		b = printf("[W0mpo Char %c [%24c]]\n", 'X', 'a');
		check(a, b, ++c);

		a = ft_printf("[Ñocla >%-*c<sadsaf]\n", 14, '$');
		b = printf("[Ñocla >%-*c<sadsaf]\n", 14, '$');
		check(a, b, ++c);

		a = ft_printf("[%c%%-12c]\n", '>');
		b = printf("[%c%%-12c]\n", '>');
		check(a, b, ++c);

		a = ft_printf("[Eskusim%25c wacaclo >%.*c]\n", 'B', 25, 'J');
		b = printf("[Eskusim%25c wacaclo >%.*c]\n", 'B', 25, 'J');
		check(a, b, ++c);

		a = ft_printf("[%025c sopita <as%.*c!0!]\n", 'C', 15, 'X');
		b = printf("[%025c sopita <as%.*c!0!]\n", 'C', 15, 'X');
		check(a, b, ++c);

		a = ft_printf("[%025c ñoclito <as%.*c!0!]\n", 'C', -15, 'X');
		b = printf("[%025c ñoclito <as%.*c!0!]\n", 'C', -15, 'X');
		check(a, b, ++c);

		a = ft_printf("[%0*c ñoclito <as%.*c!0!]\n", 'C', -2, -15, 'X');
		b = printf("[%0*c ñoclito <as%.*c!0!]\n", 'C', -2, -15, 'X');
		check(a, b, ++c);

		a = ft_printf("[%*c]\n", -30, 'J');
		b = printf("[%*c]\n", -30, 'J');
		check(a, b, ++c);

		a = ft_printf("[%.*c]\n", -30, 'J');
		b = printf("[%.*c]\n", -30, 'J');
		check(a, b, ++c);

		a = ft_printf("[%-*c]\n", -30, 'J');
		b = printf("[%-*c]\n", -30, 'J');
		check(a, b, ++c);

		a = ft_printf("[%-*c]\n", -30, NULL);
		b = printf("[%-*c]\n", -30, NULL);
		check(a, b, ++c);

		a = ft_printf("[%*c]\n", -30, NULL);
		b = printf("[%*c]\n", -30, NULL);
		check(a, b, ++c);

		a = ft_printf("[%0*c]\n", -30, NULL);
		b = printf("[%0*c]\n", -30, NULL);
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %c [%**24c]]\n", 'X', 12, 5000, 'a');
		b = printf("[W0mpo Char %c [%**24c]]\n", 'X', 12, 5000, 'a');
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %c [%**-**24c]]\n", 'X', 12, 5000, 'a');
		b = printf("[W0mpo Char %c [%**-**24c]]\n", 'X', 12, 5000, 'a');
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %c [%.**24c]]\n", 'X', 44, 24, 'a');
		b = printf("[W0mpo Char %c [%.**24c]]\n", 'X', 44, 24, 'a');
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %c [%-**24c]]\n", 'X', 44, 24, 'a');
		b = printf("[W0mpo Char %c [%-**24c]]\n", 'X', 44, 24, 'a');
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %c [%-**-**24c]]\n", 'X', 44, 24, 'a');
		b = printf("[W0mpo Char %c [%-**-**24c]]\n", 'X', 44, 24, 'a');
		check(a, b, ++c);

		a = ft_printf("[%0*c]\n", -30, 'A');
		b = printf("[%0*c]\n", -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*c]\n", -30, 'A');
		b = printf("[Width negativa %*c]\n", -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*c]\n", -30, 'A');
		b = printf("[Precision negativa %.*c]\n", -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*c]\n", -30, 'A');
		b = printf("[Precision negativa y 0 %025.*c]\n", -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*c]\n", -12, -30, 'A');
		b = printf("[Precision negativa y 0 neg %0*.*c]\n", -12, -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*c]\n", 0, 'A');
		b = printf("[Width 0 %*c]\n", 0, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*c]\n", 0, 'A');
		b = printf("[Precision 0 %.*c]\n", 0, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*c]\n", 0, 'A');
		b = printf("[Precision 0 y 0 %025.*c]\n", 0, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*c]\n", -12, 0, 'A');
		b = printf("[Precision 0 y 0 neg %0*.*c]\n", -12, 0, 'A');
		check(a, b, ++c);
	}
	if (specifier == '%' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    %%    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		a = ft_printf("[%%]\n");
		b = printf("[%%]\n");
		check(a, b, ++c);

		a = ft_printf("[W0mpo! %% %% [%24%]]\n");
		b = printf("[W0mpo! %% %% [%24%]]\n");
		check(a, b, ++c);

		a = ft_printf("[Ñocdsala >%-*%<ssdafaar]\n", 14);
		b = printf("[Ñocdsala >%-*%<ssdafaar]\n", 14);
		check(a, b, ++c);

		a = ft_printf("[%%%%-12%%]\n");
		b = printf("[%%%%-12%%]\n");
		check(a, b, ++c);

		a = ft_printf("[dsa%25% dsdddd >%.*%]\n", 25);
		b = printf("[dsa%25% dsdddd >%.*%]\n", 25);
		check(a, b, ++c);

		a = ft_printf("[%025% sopita <as%.*%!0!]\n", 15);
		b = printf("[%025% sopita <as%.*%!0!]\n", 15);
		check(a, b, ++c);

		a = ft_printf("[%025% ñoclito <as%.*%!0!]\n", -15);
		b = printf("[%025% ñoclito <as%.*%!0!]\n", -15);
		check(a, b, ++c);

		a = ft_printf("[%0*% ñoclito <as%.*%!0!]\n", -2, -15);
		b = printf("[%0*% ñoclito <as%.*%!0!]\n", -2, -15);
		check(a, b, ++c);

		a = ft_printf("[%*%]\n", -30);
		b = printf("[%*%]\n", -30);
		check(a, b, ++c);

		a = ft_printf("[%.*%]\n", -30);
		b = printf("[%.*%]\n", -30);
		check(a, b, ++c);

		a = ft_printf("[%-*%]\n", -30);
		b = printf("[%-*%]\n", -30);
		check(a, b, ++c);

		a = ft_printf("[%-*%]\n", -30);
		b = printf("[%-*%]\n", -30);
		check(a, b, ++c);

		a = ft_printf("[%*%]\n", -30);
		b = printf("[%*%]\n", -30);
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %% [%**24%]]\n", 12, 5000);
		b = printf("[W0mpo Char %% [%**24%]]\n", 12, 5000);
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %% [%**-**24%]]\n", 12, 5000);
		b = printf("[W0mpo Char %% [%**-**24%]]\n", 12, 5000);
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %% [%.**24%]]\n", 44, 24);
		b = printf("[W0mpo Char %% [%.**24%]]\n", 44, 24);
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %% [%.**.**24%]]\n", 44, 24);
		b = printf("[W0mpo Char %% [%.**.**24%]]\n", 44, 24);
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %% [%-**24%]]\n", 44, 24);
		b = printf("[W0mpo Char %% [%-**24%]]\n", 44, 24);
		check(a, b, ++c);

		a = ft_printf("[W0mpo Char %% [%-**-**24%]]\n", 44, 24);
		b = printf("[W0mpo Char %% [%-**-**24%]]\n", 44, 24);
		check(a, b, ++c);

		a = ft_printf("[%-*%]\n", '\0');
		b = printf("[%-*%]\n", '\0');
		check(a, b, ++c);

		a = ft_printf("[%0*%]\n", -30);
		b = printf("[%0*%]\n", -30);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*%]\n", -30, 'A');
		b = printf("[Width negativa %*%]\n", -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*%]\n", -30, 'A');
		b = printf("[Precision negativa %.*%]\n", -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*%]\n", -30, 'A');
		b = printf("[Precision negativa y 0 %025.*%]\n", -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*%]\n", -12, -30, 'A');
		b = printf("[Precision negativa y 0 neg %0*.*%]\n", -12, -30, 'A');
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*%]\n", 0, 'A');
		b = printf("[Width 0 %*%]\n", 0, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*%]\n", 0, 'A');
		b = printf("[Precision 0 %.*%]\n", 0, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*%]\n", 0, 'A');
		b = printf("[Precision 0 y 0 %025.*%]\n", 0, 'A');
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*%]\n", -12, 0, 'A');
		b = printf("[Precision 0 y 0 neg %0*.*%]\n", -12, 0, 'A');
		check(a, b, ++c);
	}
	if (specifier == 's' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    STRING    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		a = ft_printf("[%s]\n", "sapato");
		b = printf("[%s]\n", "sapato");
		check(a, b, ++c);

		a = ft_printf("[Sapatito %s]\n", "sapato");
		b = printf("[Sapatito %s]\n", "sapato");
		check(a, b, ++c);

		a = ft_printf("[Sapatito %.*s]\n", 12, "sapatito de aleli");
		b = printf("[Sapatito %.*s]\n", 12, "sapatito de aleli");
		check(a, b, ++c);

		a = ft_printf("[Sapatito %012s]\n", "wompo");
		b = printf("[Sapatito %012s]\n", "wompo");
		check(a, b, ++c);

		a = ft_printf("[Sapatito %12s]\n", "sopete");
		b = printf("[Sapatito %12s]\n", "sopete");
		check(a, b, ++c);

		a = ft_printf("[spaosa %12s]\n", NULL);
		b = printf("[spaosa %12s]\n", NULL);
		check(a, b, ++c);

		a = ft_printf("[spaosa %-12s]\n", NULL);
		b = printf("[spaosa %-12s]\n", NULL);
		check(a, b, ++c);

		a = ft_printf("[spaosa %-012s]\n", NULL);
		b = printf("[spaosa %-012s]\n", NULL);
		check(a, b, ++c);

		a = ft_printf("[spaosa %.*s]\n", 12, NULL);
		b = printf("[spaosa %.*s]\n", 12, NULL);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*s]\n", -30, "Sapato");
		b = printf("[Width negativa %*s]\n", -30, "Sapato");
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*s]\n", -30, "Sapato");
		b = printf("[Precision negativa %.*s]\n", -30, "Sapato");
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*s]\n", -30, "Sapato");
		b = printf("[Precision negativa y 0 %025.*s]\n", -30, "Sapato");
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*s]\n", -12, -30, "Sapato");
		b = printf("[Precision negativa y 0 neg %0*.*s]\n", -12, -30, "Sapato");
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*s]\n", 0, "Sapato");
		b = printf("[Width 0 %*s]\n", 0, "Sapato");
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*s]\n", 0, "Sapato");
		b = printf("[Precision 0 %.*s]\n", 0, "Sapato");
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*s]\n", 0, "Sapato");
		b = printf("[Precision 0 y 0 %025.*s]\n", 0, "Sapato");
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*s]\n", -12, 0, "Sapato");
		b = printf("[Precision 0 y 0 neg %0*.*s]\n", -12, 0, "Sapato");
		check(a, b, ++c);
	}
	if (specifier == 'd' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    INTEGER(d)    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		a = ft_printf("[%d]\n", 15);
		b = printf("[%d]\n", 15);
		check(a, b, ++c);

		a = ft_printf("[waaaaaa %d]\n", 15);
		b = printf("[waaaaaa %d]\n", 15);
		check(a, b, ++c);

		a = ft_printf("[Sapatito %.*d]\n", 12, 2342);
		b = printf("[Sapatito %.*d]\n", 12, 2342);
		check(a, b, ++c);

		a = ft_printf("[Safadsapatito %012d]\n", 14223);
		b = printf("[Safadsapatito %012d]\n", 14223);
		check(a, b, ++c);

		a = ft_printf("[warmopitea %12d]\n", 2312314);
		b = printf("[warmopitea %12d]\n", 2312314);
		check(a, b, ++c);

		a = ft_printf("[ñoclo %*d]\n", 12, 2312314);
		b = printf("[ñoclo %*d]\n", 12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[pipo %*d]\n", -12, 2312314);
		b = printf("[pipo %*d]\n", -12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[sa %-*d]\n", -12, 2312314);
		b = printf("[sa %-*d]\n", -12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[wa %-*d]\n", 12, 2312314);
		b = printf("[wa %-*d]\n", 12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[this %d number]\n", 17);
		b = printf("[this %d number]\n", 17);
		check(a, b, ++c);

		a = ft_printf("[%07d]\n", -54);
		b = printf("[%07d]\n", -54);
		check(a, b, ++c);

		a = ft_printf("[%022d]\n", -254);
		b = printf("[%022d]\n", -254);
		check(a, b, ++c);

		a = ft_printf("[%022d]\n", 254);
		b = printf("[%022d]\n", 254);
		check(a, b, ++c);

		a = ft_printf("[%d]\n", INT_MIN);
		b = printf("[%d]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%012d]\n", INT_MIN);
		b = printf("[%012d]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%05.12d]\n", INT_MIN);
		b = printf("[%05.12d]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%-05.12d]\n", INT_MIN);
		b = printf("[%-05.12d]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%d]\n", INT_MAX);
		b = printf("[%d]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%012d]\n", INT_MAX);
		b = printf("[%012d]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%05.12d]\n", INT_MAX);
		b = printf("[%05.12d]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-05.12d]\n", INT_MAX);
		b = printf("[%-05.12d]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-d]\n", INT_MAX);
		b = printf("[%-d]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-d]\n", INT_MIN);
		b = printf("[%-d]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*d]\n", -30, 1234);
		b = printf("[Width negativa %*d]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*d]\n", -30, 1234);
		b = printf("[Precision negativa %.*d]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*d]\n", -30, 1234);
		b = printf("[Precision negativa y 0 %025.*d]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*d]\n", -12, -30, 1234);
		b = printf("[Precision negativa y 0 neg %0*.*d]\n", -12, -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*d]\n", 0, 1234);
		b = printf("[Width 0 %*d]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*d]\n", 0, 1234);
		b = printf("[Precision 0 %.*d]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*d]\n", 0, 1234);
		b = printf("[Precision 0 y 0 %025.*d]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*d]\n", -12, 0, 1234);
		b = printf("[Precision 0 y 0 neg %0*.*d]\n", -12, 0, 1234);
		check(a, b, ++c);
	}
	if (specifier == 'i' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    INTEGER(i)    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;
		a = ft_printf("[%i]\n", 15);
		b = printf("[%i]\n", 15);
		check(a, b, ++c);

		a = ft_printf("[waaaaaa %i]\n", 15);
		b = printf("[waaaaaa %i]\n", 15);
		check(a, b, ++c);

		a = ft_printf("[Sapatito %.*i]\n", 12, 2342);
		b = printf("[Sapatito %.*i]\n", 12, 2342);
		check(a, b, ++c);

		a = ft_printf("[Safadsapatito %012i]\n", 14223);
		b = printf("[Safadsapatito %012i]\n", 14223);
		check(a, b, ++c);

		a = ft_printf("[warmopitea %12i]\n", 2312314);
		b = printf("[warmopitea %12i]\n", 2312314);
		check(a, b, ++c);

		a = ft_printf("[ñoclo %*i]\n", 12, 2312314);
		b = printf("[ñoclo %*i]\n", 12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[pipo %*i]\n", -12, 2312314);
		b = printf("[pipo %*i]\n", -12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[sa %-*i]\n", -12, 2312314);
		b = printf("[sa %-*i]\n", -12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[wa %-*i]\n", 12, 2312314);
		b = printf("[wa %-*i]\n", 12, 2312314);
		check(a, b, ++c);

		a = ft_printf("[this %i number]\n", 17);
		b = printf("[this %i number]\n", 17);
		check(a, b, ++c);

		a = ft_printf("[%07i]\n", -54);
		b = printf("[%07i]\n", -54);
		check(a, b, ++c);

		a = ft_printf("[%022i]\n", -254);
		b = printf("[%022i]\n", -254);
		check(a, b, ++c);

		a = ft_printf("[%022i]\n", 254);
		b = printf("[%022i]\n", 254);
		check(a, b, ++c);

		a = ft_printf("[%i]\n", INT_MIN);
		b = printf("[%i]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%012i]\n", INT_MIN);
		b = printf("[%012i]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%05.12i]\n", INT_MIN);
		b = printf("[%05.12i]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%-05.12i]\n", INT_MIN);
		b = printf("[%-05.12i]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[%i]\n", INT_MAX);
		b = printf("[%i]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%012i]\n", INT_MAX);
		b = printf("[%012i]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%05.12i]\n", INT_MAX);
		b = printf("[%05.12i]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-05.12i]\n", INT_MAX);
		b = printf("[%-05.12i]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-i]\n", INT_MAX);
		b = printf("[%-i]\n", INT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-i]\n", INT_MIN);
		b = printf("[%-i]\n", INT_MIN);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*i]\n", -30, 1234);
		b = printf("[Width negativa %*i]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*i]\n", -30, 1234);
		b = printf("[Precision negativa %.*i]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*i]\n", -30, 1234);
		b = printf("[Precision negativa y 0 %025.*i]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*i]\n", -12, -30, 1234);
		b = printf("[Precision negativa y 0 neg %0*.*i]\n", -12, -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*i]\n", 0, 1234);
		b = printf("[Width 0 %*i]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*i]\n", 0, 1234);
		b = printf("[Precision 0 %.*i]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*i]\n", 0, 1234);
		b = printf("[Precision 0 y 0 %025.*i]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*i]\n", -12, 0, 1234);
		b = printf("[Precision 0 y 0 neg %0*.*i]\n", -12, 0, 1234);
		check(a, b, ++c);
	}
	if (specifier == 'u' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    UNSIGNED INT    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0; //UNSIGNED INT MAX => 4294967295

		a = ft_printf("[%u]\n", UINT_MAX);
		b = printf("[%u]\n", UINT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%012u]\n", UINT_MAX);
		b = printf("[%012u]\n", UINT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%052u]\n", UINT_MAX);
		b = printf("[%052u]\n", UINT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%05.12u]\n", UINT_MAX);
		b = printf("[%05.12u]\n", UINT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%05.72u]\n", UINT_MAX);
		b = printf("[%05.72u]\n", UINT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-05.12u]\n", UINT_MAX);
		b = printf("[%-05.12u]\n", UINT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%-050.42u]\n", UINT_MAX);
		b = printf("[%-050.42u]\n", UINT_MAX);
		check(a, b, ++c);

		a = ft_printf("[%u]\n", 0);
		b = printf("[%u]\n", 0);
		check(a, b, ++c);

		a = ft_printf("[%12u]\n", 0);
		b = printf("[%12u]\n", 0);
		check(a, b, ++c);

		a = ft_printf("[%012u]\n", 0);
		b = printf("[%012u]\n", 0);
		check(a, b, ++c);
		a = ft_printf("[%.*u]\n", -12, 0);
		b = printf("[%.*u]\n", -12, 0);
		check(a, b, ++c);

		a = ft_printf("[%u]\n", 124222);
		b = printf("[%u]\n", 124222);
		check(a, b, ++c);

		a = ft_printf("[%12u]\n", 124222);
		b = printf("[%12u]\n", 124222);
		check(a, b, ++c);

		a = ft_printf("[%012u]\n", 124222);
		b = printf("[%012u]\n", 124222);
		check(a, b, ++c);

		a = ft_printf("[%.*u]\n", -12, 124222);
		b = printf("[%.*u]\n", -12, 124222);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*u]\n", -30, 1234);
		b = printf("[Width negativa %*u]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*u]\n", -30, 1234);
		b = printf("[Precision negativa %.*u]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*u]\n", -30, 1234);
		b = printf("[Precision negativa y 0 %025.*u]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*u]\n", -12, -30, 1234);
		b = printf("[Precision negativa y 0 neg %0*.*u]\n", -12, -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*u]\n", 0, 1234);
		b = printf("[Width 0 %*u]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*u]\n", 0, 1234);
		b = printf("[Precision 0 %.*u]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*u]\n", 0, 1234);
		b = printf("[Precision 0 y 0 %025.*u]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*u]\n", -12, 0, 1234);
		b = printf("[Precision 0 y 0 neg %0*.*u]\n", -12, 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 y -%025.*u]\n", 0, -1234);
		b = printf("[Precision 0 y 0 y -%025.*u]\n", 0, -1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*u]\n", -12, 0, -1234);
		b = printf("[Precision 0 y 0 neg %0*.*u]\n", -12, 0, -1234);
		check(a, b, ++c);
	}
	if (specifier == 'p' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    POINTER    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		unsigned long long u = 299792458000000000ULL;
		a = ft_printf("[%p]\n", (void *)&b);
		b = printf("[%p]\n", (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%32p]\n", (void *)&b);
		b = printf("[%32p]\n", (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%.32p]\n", (void *)&b);
		b = printf("[%.32p]\n", (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%.*p]\n", 32, (void *)&b);
		b = printf("[%.*p]\n", 32, (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%*p]\n", 32, (void *)&b);
		b = printf("[%*p]\n", 32, (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%-32p]\n", (void *)&b);
		b = printf("[%-32p]\n", (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%032p]\n", (void *)&b);
		b = printf("[%032p]\n", (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%*p]\n", 40, (void *)&b);
		b = printf("[%*p]\n", 40, (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%-*p]\n", 40, (void *)&b);
		b = printf("[%-*p]\n", 40, (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%*.*p]\n", 40, 50, (void *)&b);
		b = printf("[%*.*p]\n", 40, 50, (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[%*p]\n", -40, (void *)&b);
		b = printf("[%*p]\n", -40, (void *)&b);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*p]\n", -30, (void *)&leaks);
		b = printf("[Width negativa %*p]\n", -30, (void *)&leaks);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*p]\n", -30, (void *)&leaks);
		b = printf("[Precision negativa %.*p]\n", -30, (void *)&leaks);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*p]\n", -30, (void *)&leaks);
		b = printf("[Precision negativa y 0 %025.*p]\n", -30, (void *)&leaks);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*p]\n", -12, -30, (void *)&leaks);
		b = printf("[Precision negativa y 0 neg %0*.*p]\n", -12, -30, (void *)&leaks);
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*p]\n", 0, (void *)&leaks);
		b = printf("[Width 0 %*p]\n", 0, (void *)&leaks);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*p]\n", 0, (void *)&leaks);
		b = printf("[Precision 0 %.*p]\n", 0, (void *)&leaks);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*p]\n", 0, (void *)&leaks);
		b = printf("[Precision 0 y 0 %025.*p]\n", 0, (void *)&leaks);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*p]\n", -12, 0, (void *)&leaks);
		b = printf("[Precision 0 y 0 neg %0*.*p]\n", -12, 0, (void *)&leaks);
		check(a, b, ++c);
	}
	if (specifier == 'x' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    HEX(x)    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		a = ft_printf("[%.*x]\n", 0, 1234);
		b = printf("[%.*x]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[%.*x]\n", 1, 1234);
		b = printf("[%.*x]\n", 1, 1234);
		check(a, b, ++c);

		a = ft_printf("[%.*x]\n", -1, 1234);
		b = printf("[%.*x]\n", -1, 1234);
		check(a, b, ++c);

		a = ft_printf("[%.*x]\n", -20, 1234);
		b = printf("[%.*x]\n", -20, 1234);
		check(a, b, ++c);

		a = ft_printf("[%012.*x]\n", -1, 1234);
		b = printf("[%012.*x]\n", -1, 1234);
		check(a, b, ++c);

		a = ft_printf("[%012.*x]\n", 12, 1234);
		b = printf("[%012.*x]\n", 12, 1234);
		check(a, b, ++c);

		a = ft_printf("[%012.*x]\n", 112, 1234);
		b = printf("[%012.*x]\n", 112, 1234);
		check(a, b, ++c);
		a = ft_printf("[%012.*x]\n", 0, 1234);
		b = printf("[%012.*x]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*x]\n", -30, 1234);
		b = printf("[Width negativa %*x]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*x]\n", -30, 1234);
		b = printf("[Precision negativa %.*x]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*x]\n", -30, 1234);
		b = printf("[Precision negativa y 0 %025.*x]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*x]\n", -12, -30, 1234);
		b = printf("[Precision negativa y 0 neg %0*.*x]\n", -12, -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*x]\n", 0, 1234);
		b = printf("[Width 0 %*x]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*x]\n", 0, 1234);
		b = printf("[Precision 0 %.*x]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*x]\n", 0, 1234);
		b = printf("[Precision 0 y 0 %025.*x]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*x]\n", -12, 0, 1234);
		b = printf("[Precision 0 y 0 neg %0*.*x]\n", -12, 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 y -%025.*x]\n", 0, -1234);
		b = printf("[Precision 0 y 0 y -%025.*x]\n", 0, -1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*x]\n", -12, 0, -1234);
		b = printf("[Precision 0 y 0 neg %0*.*x]\n", -12, 0, -1234);
		check(a, b, ++c);
	}
	if (specifier == 'X' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    HEX(X)    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		a = ft_printf("[%.*X]\n", 0, 1234);
		b = printf("[%.*X]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[%.*X]\n", 1, 1234);
		b = printf("[%.*X]\n", 1, 1234);
		check(a, b, ++c);

		a = ft_printf("[%.*X]\n", -1, 1234);
		b = printf("[%.*X]\n", -1, 1234);
		check(a, b, ++c);

		a = ft_printf("[%.*X]\n", -20, 1234);
		b = printf("[%.*X]\n", -20, 1234);
		check(a, b, ++c);

		a = ft_printf("[%012.*X]\n", -1, 1234);
		b = printf("[%012.*X]\n", -1, 1234);
		check(a, b, ++c);

		a = ft_printf("[%012.*X]\n", 12, 1234);
		b = printf("[%012.*X]\n", 12, 1234);
		check(a, b, ++c);

		a = ft_printf("[%012.*X]\n", 112, 1234);
		b = printf("[%012.*X]\n", 112, 1234);
		check(a, b, ++c);

		a = ft_printf("[%012.*X]\n", 0, 1234);
		b = printf("[%012.*X]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Width negativa %*X]\n", -30, 1234);
		b = printf("[Width negativa %*X]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa %.*X]\n", -30, 1234);
		b = printf("[Precision negativa %.*X]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 %025.*X]\n", -30, 1234);
		b = printf("[Precision negativa y 0 %025.*X]\n", -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision negativa y 0 neg %0*.*X]\n", -12, -30, 1234);
		b = printf("[Precision negativa y 0 neg %0*.*X]\n", -12, -30, 1234);
		check(a, b, ++c);

		a = ft_printf("[Width 0 %*X]\n", 0, 1234);
		b = printf("[Width 0 %*X]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 %.*X]\n", 0, 1234);
		b = printf("[Precision 0 %.*X]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 %025.*X]\n", 0, 1234);
		b = printf("[Precision 0 y 0 %025.*X]\n", 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*X]\n", -12, 0, 1234);
		b = printf("[Precision 0 y 0 neg %0*.*X]\n", -12, 0, 1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 y -%025.*X]\n", 0, -1234);
		b = printf("[Precision 0 y 0 y -%025.*X]\n", 0, -1234);
		check(a, b, ++c);

		a = ft_printf("[Precision 0 y 0 neg %0*.*X]\n", -12, 0, -1234);
		b = printf("[Precision 0 y 0 neg %0*.*X]\n", -12, 0, -1234);
		check(a, b, ++c);
	}
	if (specifier == 'A' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    MIX    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;

		a = ft_printf("[%s, de %.*d años, nacido el %d de %s de %5d]\n", "Carlos", 5, 24, 28, "Noviembre", 1996);
		b = printf("[%s, de %.*d años, nacido el %d de %s de %5d]\n", "Carlos", 5, 24, 28, "Noviembre", 1996);
		check(a, b, ++c);

		a = ft_printf("[%.*X]\n", -1, 0);
		b = printf("[%.*X]\n", -1, 0);
		check(a, b, ++c);

		a = ft_printf("[Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p]\n", 100, "Ly", &a);
		b = printf("[Lalalala, %d%% des gens qui parlent à Ly adorent %s. Ou Presque. %p]\n", 100, "Ly", &a);
		check(a, b, ++c);

		a = ft_printf("[%%i 0000042 == |%i|]\n", 0000042);
		b = printf("[%%i 0000042 == |%i|]\n", 0000042);
		check(a, b, ++c);

		a = ft_printf("[%i]\n", 0000042);
		b = printf("[%i]\n", 0000042);
		check(a, b, ++c);

		a = ft_printf("[%%i 42 = %i]\n", 0000042);
		b = printf("[%%i 42 = %i]\n", 0000042);
		check(a, b, ++c);

		a = ft_printf("[%i 42 = %i]\n", 0000042);
		b = printf("[%i 42 = %i]\n", 0000042);
		check(a, b, ++c);

		a = ft_printf("[%05s, <3]\n", "https://d1dd4ethwnlwo2.cloudfront.net/wp-content/uploads/2020/01/mork.jpg");
		b = printf("[%05s, <3]\n", "https://d1dd4ethwnlwo2.cloudfront.net/wp-content/uploads/2020/01/mork.jpg");
		check(a, b, ++c);
	}
	if (specifier == 'n' || specifier == '\0')
	{
		printf("░░░░▒▒▒▒▒▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓    BONUS(n)    ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▒▒▒▒▒░░░░\n\n");
		printf("▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄\n\n");
		c = 0;
		int j = 13;
		printf("n previo = %d\n", j);
		a = ft_printf("[Sapato %n]\n", &j);
		printf("FT_PRINTF n = %d\n", j);
		j = 13;
		b = printf("[Sapato %n]\n", &j);
		printf("PRINTF n = %d\n", j);
		check(a, b, ++c);
	}
	if (leaks)
		system("leaks a.out");
	return (0);
}
*/
