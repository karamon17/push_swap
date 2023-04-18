/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:19:03 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/17 18:19:04 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_2to_b(t_list	**a, t_list	**b)
{
	if (get_list_length(*a) >= 5)
	{
		pa_or_pb(a, b, "pb\n");
		pa_or_pb(a, b, "pb\n");
	}
	else if (get_list_length(*a) >= 4)
		pa_or_pb(a, b, "pb\n");
}

int	find_index(t_list *stack, int num)
{
	int	index;

	index = 0;
	while (stack->data != num)
	{
		stack = stack->next;
		index++;
	}
	return (index);
}

int	find_nearest(t_list *head, int num)
{
	t_list	*current;

	while (1)
	{
		num--;
		current = head;
		while (current->next != head)
		{	
			if (current->data == num)
				return (num);
			current = current->next;
		}
		if (current->data == num)
			return (num);
	}
}
