/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:49:43 by cmarcu            #+#    #+#             */
/*   Updated: 2021/04/02 16:56:49 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# include "libft/libft.h"

typedef struct s_format
{
	size_t		flag_minus;
	size_t		flag_zero;
	int			width;
	int			precision;
	char		specifier;
	size_t		p_has_changed;
	int			chars_printed;
}				t_format;

typedef struct s_lengths
{
	int		res_length;
	int		arg_length;
}				t_lengths;

int				ft_printf(const char *str, ...);
int				ft_string_looper(va_list *vl, t_format *format,
					t_lengths *lengths, const char *str);

void			ft_init_format(t_format *format);
void			ft_init_lengths(t_lengths *lengths, char *str_from_arg,
					t_format *format);
void			ft_get_flags(char *str, int i, t_format *format);
int				ft_check_formatters(va_list *vl, char *str, int i,
					t_format *format);
int				check_f_flags(t_format *format, char *str, int i, int *result);
int				check_f_width(t_format *format, char *str, int i,
					int *p_result);
int				check_f_width_vl(t_format *format, va_list *vl, int i,
					int *p_result);
int				check_f_prec(t_format *format, char *str, int i, int *p_result);
int				check_f_prec_vl(t_format *format, va_list *vl, int i,
					int *p_result);
void			check_f_prec_not(t_format *format, int *p_result);
void			check_specifier(char *str, int i, t_format *format);

char			*ft_arg_to_string(va_list *vl, t_format *format);
char			*ft_handle_c(va_list *vl);
char			*ft_handle_s(va_list *vl);
char			*ft_handle_p(va_list *vl);
char			*ft_handle_di(va_list *vl);
char			*ft_handle_u(va_list *vl);
char			*ft_handle_x(va_list *vl);
char			*ft_handle_X(va_list *vl);
char			*ft_strtoupper(char *str_from_arg);

int				ft_get_length(char *str_from_arg, t_format *format);
int				ft_get_string_length(char *str_from_arg, t_format *format);
int				ft_get_char_length(t_format *format);
int				ft_get_pointer_length(t_format *format, char *str_from_arg);
int				ft_number_length(int n);
int				ft_get_integer_length(char *str_from_arg, t_format *format);
int				ft_unsigned_number_length(unsigned int n);
int				ft_get_unsigned_length(char *str_from_arg, t_format *format);

void			ft_putnchar(char c, int n);

int				integer_length(int n);

void			ft_print_arg(char *str_from_arg, t_format *format,
					t_lengths *lengths);
void			ft_print_string(char *str_from_arg, t_format *format,
					t_lengths *lengths);
void			ft_print_char(char *str_from_arg, t_format *format,
					t_lengths *lengths);
void			ft_print_pointer(char *str_from_arg, t_format *format,
					t_lengths *lengths);
void			print_address(t_format *format, t_lengths *lengths, char *str);

char			*ft_itoa_base(unsigned long long n, unsigned long long base);
int				itoa_base_length(unsigned long long int n,
					unsigned long long base);

void			ft_print_integer(char *str_from_arg, t_format *format,
					t_lengths *lengths);
int				get_diff(t_format *format, t_lengths *lengths);
void			di_handle_width(char *str_from_arg, t_format *format,
					t_lengths *lengths, int diff);
void			di_handle_neg_width(char *str_from_arg, t_format *format,
					t_lengths *lengths, int diff);
void			ft_handle_minusflag_neg(char *substr, t_format *format,
					t_lengths *lengths, int diff);
void			ft_print_positive(char *str_from_arg, t_format *format,
					t_lengths *lengths, int diff);
void			ft_print_negative(char *str_from_arg, t_format *format,
					t_lengths *lengths, int diff);
void			ft_print_unsigned(char *str_from_arg, t_format *format,
					t_lengths *lengths);
void			ft_print_hex(char *str_from_arg, t_format *format,
					t_lengths *lengths);

#endif
