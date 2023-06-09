/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:20:19 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/21 15:20:21 by gkhaishb         ###   ########.fr       */
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

void	sa_or_sb(t_list **stack, char *str)
{
	if (*stack && (*stack)->next)
		swap(stack);
	write(1, str, ft_strlen(str));
}
