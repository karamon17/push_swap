/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:43:34 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/12 19:43:36 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_list_length(t_list *head)
{
	int		length;
	t_list	*current;

	length = 1;
	current = head;
	if (head == NULL)
	{
		return (0);
	}
	while (current->next != head)
	{
		length++;
		current = current->next;
	}
	return (length);
}

int	find_max(t_list *head)
{
	int		max;
	t_list	*current;

	current = head;
	max = current->data;
	while (current->next != head)
	{
		if (current->data > max)
			max = current->data;
		current = current->next;
	}
	if (current->data > max)
		max = current->data;
	return (max);
}

int	find_min(t_list *head)
{
	int		min;
	t_list	*current;

	current = head;
	min = current->data;
	while (current->next != head)
	{
		if (current->data < min)
			min = current->data;
		current = current->next;
	}
	if (current->data < min)
		min = current->data;
	return (min);
}

void	sort_three(t_list	**a, int *count)
{
	if ((*a)->data > (*a)->next->data && \
		(*a)->next->data > (*a)->next->next->data)
	{
		sa_or_sb(a, count);
		rra_or_rrb(a, count);
	}
	else if ((*a)->data < (*a)->next->data && \
		(*a)->next->next->data < (*a)->data)
		rra_or_rrb(a, count);
	else if ((*a)->data < (*a)->next->data)
	{
		sa_or_sb(a, count);
		ra_or_rb(a, count);
	}
	else if ((*a)->data > (*a)->next->data && \
		(*a)->next->data < (*a)->next->next->data)
	{
		ra_or_rb(a, count);
	}
}

int	check_sort_stack(t_list	**a)
{
	t_list	*current;

	current = *a;
	while (current->next != *a)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
