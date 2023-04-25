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

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}						t_list;

typedef struct s_score
{
	int		min_score;
	int		score;
	int		i;
	int		j;
	t_list	*current_b;
	t_list	*current_a;
}						t_score;

int		ft_atoi(const char *str, char **arr);
int		ft_isdigit(int arg);
t_list	*ft_lstnew(int data);
void	check_argumets(int argc, char **argv);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	sa_or_sb(t_list **stack, char *str);
void	pa_or_pb(t_list **in, t_list **out, char *str);
void	ra_or_rb(t_list **stack, char *str);
void	rr(t_list **a, t_list **b);
void	rra_or_rrb(t_list **stack, char *str);
void	rrr(t_list **a, t_list **b);
void	sorting(t_list	**a, t_list	**b);
int		get_list_length(t_list *head);
int		find_max(t_list *head);
int		find_min(t_list *head);
void	sort_three(t_list	**a);
int		check_sort_stack(t_list	*head);
size_t	ft_strlen(const char *str);
void	push_2to_b(t_list	**a, t_list	**b);
int		find_index(t_list *stack, int num);
int		find_nearest(t_list *head, int num);
void	current_nearest(t_list *b, int *num, t_score *find);
void	current_maxmin(t_list *b, int *num, t_score *find);
void	find_min_score(t_list *a, t_list *b, int *num, t_score *find);
void	rotate_push_minmax(t_list	**a, t_list	**b, int num);
int		find_nearest_bigger(t_list *head, int num);
void	free_arr(char **arr);
void	error(t_list *a, t_list *b, char **arr);
void	free_lst(t_list	*a);
void	free_str(char *str);
void	check_str(char *ar, char *str);

#endif