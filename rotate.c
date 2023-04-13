/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:19:18 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/10 18:19:20 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_or_rb(t_list **stack, int *count)
{
	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		(*count)++;
	}
}

void	rr(t_list **a, t_list **b, int *count)
{
	int	flag;

	flag = 0;
	if (*a && (*a)->next)
	{
		ra_or_rb(a, count);
		(*count)--;
		flag = 1;
	}
	if (*b && (*b)->next)
	{
		ra_or_rb(b, count);
		(*count)--;
		flag = 1;
	}
	(*count) += flag;
}

void	rra_or_rrb(t_list **stack, int *count)
{
	if (*stack && (*stack)->prev)
	{
		*stack = (*stack)->prev;
		(*count)++;
	}
}

void	rrr(t_list **a, t_list **b, int *count)
{
	int	flag;

	flag = 0;
	if (*a && (*a)->prev)
	{
		rra_or_rrb(a, count);
		count--;
		flag = 1;
	}
	if (*b && (*b)->prev)
	{
		rra_or_rrb(b, count);
		count--;
		flag = 1;
	}
	(*count) += flag;
}
