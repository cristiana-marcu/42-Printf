/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:49:43 by cmarcu            #+#    #+#             */
/*   Updated: 2021/02/26 13:10:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

# include "libft/libft.h"

typedef struct  s_format
{
    int         flag_minus;
    int         flag_zero;
    int         width;
    int         precision;
    char        specifier;
}               t_format;

int	ft_printf(char *str, ...);

#endif
