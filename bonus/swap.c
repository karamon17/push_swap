/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:52 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/21 15:17:54 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	sa_or_sb(t_list **stack)
{
	if (*stack && (*stack)->next)
		swap(stack);
}

void	ss(t_list **a, t_list **b)
{
	if (*a && (*a)->next)
		swap(a);
	if (*b && (*b)->next)
		swap(b);
}
