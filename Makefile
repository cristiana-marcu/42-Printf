# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 12:32:23 by cmarcu            #+#    #+#              #
#    Updated: 2021/04/07 12:56:22 by cmarcu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c check_format.c check_prec.c \
	check_width.c get_length.c init.c print_char.c \
	print_integer.c print_negative.c print_pointer.c print_string.c \
	print_ux.c retrieve_string.c retrieve_string2.c utils.c
OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror
RM	= rm -f
AR	= ar rcs

NAME	= libftprintf.a

INCLUDE	= ./libft

all: $(NAME)

$(NAME): $(OBJS)
	@make re -C $(INCLUDE)
	@$(CC) -g3 $(CFLAGS) -c $(SRCS) -I.
	@ar rc $(NAME) $(OBJS) $(INCLUDE)/ft*.o
	@ranlib $(NAME)

clean:
	$(RM) $(OBJS)
	make -C $(INCLUDE)

fclean:	clean
	$(RM) $(NAME)

try: $(NAME)
	$(CC) $(CFLAGS) main.c -L. -l ftprintf -I. && ./a.out

re:	fclean $(NAME)

.PHONY:	all clean fclean re try
