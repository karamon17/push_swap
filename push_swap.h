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
t_list	*ft_lstnew(int data);
void	check_argumets(int argc, char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	sa_or_sb(t_list **stack);
void	ss(t_list **a, t_list **b);
void	pa_or_pb(t_list **in, t_list **out);
void	ra_or_rb(t_list **stack);
void	rr(t_list **a, t_list **b);
void	rra_or_rrb(t_list **stack);
void	rrr(t_list **a, t_list **b);
void	sorting(t_list	**a, t_list	**b);
int		get_list_length(t_list *head);
int	find_max(t_list *head);
int		find_min(t_list *head);
void	sort_three(t_list	**a);
int		check_sort_stack(t_list	**a);

#endif