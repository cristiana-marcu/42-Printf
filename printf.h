/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:49:43 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/10 16:24:42 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct	s_format
{
	size_t		flag_minus;
	size_t		flag_zero;
	size_t		width;
	size_t		precision;
	char		specifier;
}				t_format;

int	ft_printf(char *str, ...);

void ft_init_format(t_format *format);
void ft_get_flags(char *str, int i, t_format *format);
int ft_check_formatters(va_list *vl, char *str, int i, t_format *format);
char	*ft_arg_to_string(va_list *vl, t_format *format);

size_t	ft_get_length(char *str_from_arg, t_format *format);
size_t ft_get_string_length(char *str_from_arg, t_format *format);
size_t ft_get_char_length(t_format *format);
size_t	ft_get_pointer_length(t_format *format);
size_t	ft_number_length(int n);
size_t	ft_get_integer_length(char *str_from_arg, t_format *format);
size_t	ft_unsigned_number_length(unsigned int n);
size_t	ft_get_unsigned_length(char *str_from_arg, t_format *format);

void	ft_putnchar(char c, size_t n);

void	ft_print_arg(char *str_from_arg, t_format *format, size_t res_length);
void ft_print_string(char *str_from_arg, t_format *format, size_t res_length);
void ft_print_char(char *str_from_arg, t_format *format, size_t res_length);
void ft_print_pointer(char *str_from_arg, t_format *format, size_t res_length);
void	print_address(t_format *format, size_t res_length, char *str);

char	*ft_itoa_hex(unsigned long long n);
int	itoa_hex_length(unsigned long long int n);

void	ft_print_integer(char *str_from_arg, t_format *format, int res_length);
void ft_print_unsigned(char *str_from_arg, t_format *format, int res_length);
void ft_print_hex(char *str_from_arg, t_format *format, int res_length);

void	ft_error();

#endif
