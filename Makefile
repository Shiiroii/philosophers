# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lionelulm <lionelulm@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 17:47:58 by lionelulm         #+#    #+#              #
#    Updated: 2025/05/07 23:39:53 by lionelulm        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosophers

HEADER	= includes/philosophers.h

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

RM		= rm -f

SRCS	=	srcs/main.c				\
			srcs/utils.c			\
			srcs/mutex.c			\
			srcs/routine.c			\
			srcs/time_to_die.c		\
			srcs/time_to_eat.c		\
			srcs/initialization.c	\

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
