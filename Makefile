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

NAME2 = bonus

SRCS = $(wildcard *.c)

SRCS2 = $(addprefix ./bonus/,main.c check_arguments.c ft_split.c get_next_line.c get_next_line_utils.c libft.c push.c rotate.c sorting.c swap.c)

OBJS = $(SRCS:.c=.o)

OBJS2 = $(SRCS2:.c=.o)

HEADER = push_swap.h

HEADER2 = bonus/checker.h

HEADER_GNL = bonus/get_next_line.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME2)

%.o: %.c $(HEADER) $(HEADER2)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(HEADER) $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

$(NAME2): $(HEADER2) $(HEADER_GNL) $(OBJS2)
	echo $(SRCS2)
	cc $(FLAGS) $(OBJS2) -o checker

clean:
	rm -f $(OBJS)
	rm -f $(OBJS2)

fclean: clean
	rm -f $(NAME)
	rm -f checker

re: fclean all

.PHONY:	all clean fclean re
