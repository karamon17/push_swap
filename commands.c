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

void	pa_or_pb(t_list **in, t_list **out, int *count)
{
	t_list	*tmp;

	if (*out)
	{
		tmp = (t_list *)malloc(sizeof(t_list));
		tmp->data = (*out)->data;
		tmp->next = *in;
		tmp->prev = (*in)->prev;
		(*in)->prev = tmp;
		tmp->prev->next = tmp;
		*in = tmp;
		tmp = *out;
		tmp->next->prev = tmp->prev;
		tmp->prev->next = tmp->next;
		*out = tmp->next;
		free(tmp);
		(*count)++;
	}
}

void	ra_or_rb(t_list **stack, int *count)
{
	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*count)++;
	}
}
