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
NAME_CH = checker

SRCS = $(wildcard *.c)

SRCS2 = $(wildcard bonus/*.c)

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

HEADER = push_swap.h

HEADER2 = bonus/checker.h

HEADER_GNL = bonus/get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HEADER) $(HEADER2)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(HEADER) $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

bonus: $(NAME_CH)

$(NAME_CH): $(HEADER2) $(HEADER_GNL) $(OBJS2)
			cc $(FLAGS) $(OBJS2) -o $(NAME_CH)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS2)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_CH)

re: fclean all

.PHONY:	all clean fclean re bonus
