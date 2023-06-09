/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:17:11 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/21 15:17:13 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_or_rb(t_list **stack)
{
	if (*stack && (*stack)->next)
		*stack = (*stack)->next;
}

void	rr(t_list **a, t_list **b)
{
	if (*a && (*a)->next)
		ra_or_rb(a);
	if (*b && (*b)->next)
		ra_or_rb(b);
}

void	rra_or_rrb(t_list **stack)
{
	if (*stack && (*stack)->prev)
		*stack = (*stack)->prev;
}

void	rrr(t_list **a, t_list **b)
{
	if (*a && (*a)->prev)
		rra_or_rrb(a);
	if (*b && (*b)->prev)
		rra_or_rrb(b);
}
