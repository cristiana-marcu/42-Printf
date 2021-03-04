/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/03 17:44:34 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main()
{
	char *mystring = "ñaña";
	char mychar = 'Z';
	int mynumber = -120;
	//printf("-----------Mi resultado:----------\n");
	//ft_printf("ya imprimo strings %c %s %p %d", mychar, mystring, mystring, mynumber);
	//printf("\n");
	//printf("-----------Su resultado:----------\n");
	//printf("ya imprimo strings %c %s %p %d %x", mychar, mystring, mystring, mynumber, mynumber);
	//printf("\n");
	printf("'%.3d'", mynumber);
	write(1, &mynumber, 4);
}
