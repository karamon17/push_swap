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
# include <stdio.h>

typedef struct s_list {
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}						t_list;

int		ft_atoi(const char *str);
int		ft_isdigit(int arg);
t_list	*ft_lstnew(t_list *list, int data, t_list *head);
void	check_argumets(int argc, char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	sa_or_sb(t_list **a, int *count);
void	ss(t_list **a, t_list **b, int *count);
void	pa(t_list **a, t_list **b, int *count);
void	pb(t_list **a, t_list **b, int *count);
void	ra(t_list **a, int *count);
void	rb(t_list **b, int *count);
void	rr(t_list **a, t_list **b, int *count);
void	rra(t_list **a, int *count);
void	rrb(t_list **b, int *count);
void	rrr(t_list **a, t_list **b, int *count);

#endif