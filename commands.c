/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:12:56 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/10 18:12:58 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	(*a)->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next = *a;
	tmp->prev = (*a)->prev;
	(*a)->prev->next = tmp;
	(*a)->prev = tmp;
	*a = tmp;
}

void	sa_or_sb(t_list **a, int *count)
{
	if (*a && (*a)->next)
	{
		swap(a);
		(*count)++;
	}
}

void	ss(t_list **a, t_list **b, int *count)
{
	int	flag;

	flag = 0;
	if (*a && (*a)->next)
	{
		swap(a);
		flag = 1;
	}
	if (*b && (*b)->next)
	{
		swap(b);
		flag = 1;
	}
	(*count) += flag;
}

void	pa(t_list **a, t_list **b, int *count)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->data = (*b)->data;
		tmp->next = *a;
		tmp->prev = (*a)->prev;
		(*a)->prev = tmp;
		tmp->prev->next = tmp;
		*a = tmp;
		tmp = *b;
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		*b = tmp->next;
		free(tmp);
	}
}

void	pb(t_list **a, t_list **b, int *count)
{
	
}
