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

void	swap(t_list **stack)
{
	t_list	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next->prev = tmp->prev;
	tmp->next = *stack;
	tmp->prev = (*stack)->prev;
	(*stack)->prev->next = tmp;
	(*stack)->prev = tmp;
	*stack = tmp;
}

void	sa_or_sb(t_list **stack, int *count)
{
	if (*stack && (*stack)->next)
	{
		swap(stack);
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

void	push(t_list **from, t_list **to, t_list **tmp)
{
	if (*to)
	{
		*tmp = (*from);
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		(*from) = (*from)->next;
		(*to)->prev = *tmp;
		(*tmp)->next = (*to);
		(*to)->next = *tmp;
		(*tmp)->prev = (*to);
		(*to) = *tmp;
	}
	else
	{
		*tmp = (*from);
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		(*from) = (*from)->next;
		(*to) = *tmp;
		(*to)->prev = *tmp;
		(*to)->next = *tmp;
	}
}

void	pa_or_pb(t_list **from, t_list **to, int *count)
{
	t_list	*tmp;

	if (*from == NULL)
		return ;
	if (*from && (*from)->next == *from)
	{
		
	}
	if (*to && (*to)->next != (*to))
	{
		tmp = (*from);
		(*from)->next->prev = (*from)->prev;
		(*from)->prev->next = (*from)->next;
		(*from) = (*from)->next;
		(*to)->prev->next = tmp;
		tmp->prev = (*to)->prev;
		(*to)->prev = tmp;
		tmp->next = (*to);
		(*to) = tmp;
		(*count)++;
		return ;
	}
	push(from, to, &tmp);
	(*count)++;
}
