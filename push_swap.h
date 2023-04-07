/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:15:23 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/06 12:15:25 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list {
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}						t_list;

int		ft_atoi(const char *str);
int		ft_isdigit(int arg);
t_list	*ft_lstnew(t_list *list, int data);
void	check_argumets(int argc, char **argv);

#endif