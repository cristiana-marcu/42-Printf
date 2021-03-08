/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/08 17:53:08 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main()
{
	char *mystring = "ñaña";
	char mychar = 'Z';
	int mynumber = -120;
	printf("-----------Mi resultado:----------\n");
	ft_printf("Char:%c", mychar);
	printf("\n");
	ft_printf("Number: %d", mynumber);
	printf("\n");
	printf("-----------Su resultado:----------\n");
	printf("ya imprimo strings %c %s %p %d %x", mychar, mystring, mystring, mynumber, mynumber);
	printf("\n");
	printf("'%-5d'", mynumber);
}
