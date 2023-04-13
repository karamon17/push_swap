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
