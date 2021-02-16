# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 12:32:23 by cmarcu            #+#    #+#              #
#    Updated: 2021/02/16 17:44:14 by cmarcu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c main.c ./libft/ft*.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	libft.a

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -c
RM	= rm -f
AR	= ar rcs

NAME	= libftprintf.a

INCLUDE	= ./libft
INCLUDES = printf.h

all: $(NAME)

$(NAME):
	@make re -C $(INCLUDE)
	@$(CC) -g3 $(CFLAGS) $(SRCS) -I $(INCLUDES)
	@ar rc $(NAME) $(OBJS) $(INCLUDE)/*.o
	@ranlib $(NAME)

clean:
	$(RM) $(OBJS)
	#make -C $(INCLUDE)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY:	all clean fclean re
