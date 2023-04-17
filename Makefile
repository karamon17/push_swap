# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 11:11:54 by gkhaishb          #+#    #+#              #
#    Updated: 2023/04/03 11:11:56 by gkhaishb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = $(wildcard *.c)

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(HEADER) $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
