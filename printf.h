/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:49:43 by cmarcu            #+#    #+#             */
/*   Updated: 2021/03/01 10:59:18 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

# include "libft/libft.h"

typedef struct	s_format
{
	int			flag_minus;
	int			flag_zero;
	int			width;
	int			precision;
	char		specifier;
}				t_format;

int	ft_printf(char *str, ...);

#endif
