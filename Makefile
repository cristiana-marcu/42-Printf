# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 12:32:23 by cmarcu            #+#    #+#              #
#    Updated: 2021/03/18 12:17:28 by cmarcu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c main.c
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

.PHONY:	all clean fclean re
