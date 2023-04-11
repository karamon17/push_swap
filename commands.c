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
	t_list	*tmp;

	if (*a && (*a)->next)
	{
		swap(a);
		(*count)++;
	}
}

void	ss(t_list **a, t_list **b, int *count)
{
	t_list	*tmp;
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

}

void	pb(t_list **a, t_list **b, int *count)
{
	
}
