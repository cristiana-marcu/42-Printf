/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:44:55 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/10 16:33:35 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int	main()
{
	//char *mystring = "nono";
	//char mychar = 'Z';
	int mynumber = 120;
	ft_printf("-----------Mi resultado:----------\n");
	/*ft_printf("Char: %50c", mychar);
	ft_printf("\n");
	ft_printf("String: %s", mystring);
	ft_printf("\n");*/
	ft_printf("Number: %50.5i", mynumber);
	ft_printf("\n");
	ft_printf("-----------Su resultado:----------\n");
	/*printf("Char: %c", mychar);
	printf("\n");
	printf("String: %s", mystring);
	printf("\n");*/
	printf("Number: %50.5i", mynumber);
	printf("\n");
}
