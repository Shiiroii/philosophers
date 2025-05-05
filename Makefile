# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liulm <liulm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 14:01:26 by liulm             #+#    #+#              #
#    Updated: 2025/04/28 15:46:15 by liulm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosophers

HEADER	= includes/philosophers.h

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

RM		= rm -f

SRCS	=	srcs/main.c				\
			srcs/initialize.c		\
			srcs/time_to_die.c		\
			srcs/time_to_sleep.c	\
			srcs/time_to_think.c	\
			srcs/time_to_eat.c		\
			srcs/routine.c			\
			srcs/utils.c

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
