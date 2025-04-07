# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liulm <liulm@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/18 14:01:26 by liulm             #+#    #+#              #
#    Updated: 2025/04/05 16:05:14 by liulm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philosophers

HEADER	= includes/philosophers.h

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g3

RM		= rm -f

SRCS	=	srcs/main.c			\
			srcs/initialize.c	\

OBJS	= $(SRCS:.c=.o)

LIBFT	= ./utils/libft/libft.a

PRINTF	= ./utils/ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./utils/libft

$(PRINTF):
	$(MAKE) -C ./utils/ft_printf

clean:
	$(RM) $(OBJS)
	$(MAKE) -C ./utils/libft fclean
	$(MAKE) -C ./utils/ft_printf fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
