/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:19:53 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/10 18:19:54 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list	**a, t_list	**b)
{
	int		length_a;
	int		length_b;
	int		count;
	int		max_b;
	int		min_b;

	count = 0;
	// printf("%d это а\n", get_list_length(*a));
	// printf("%d это b\n", get_list_length(*b));
	//length_b = get_list_length(*b);
	if (get_list_length(*a) >= 5)
	{
		pa_or_pb(a, b, &count);
		pa_or_pb(a, b, &count);
	}
	else if (get_list_length(*a) >= 4)
		pa_or_pb(a, b, &count);
	//printf("%d\n", count);
	// printf("%d это а\n", get_list_length(*a));
	// printf("%d это b\n", get_list_length(*b));
	//printf("%d", (*b)->data);
	//printf("%d это второй b\n", (*b)->next->data);
	//printf("%d это max_b\n", find_max(*b));
	while(get_list_length(*a) > 3)
	{
		max_b = find_max(*b);
		min_b = find_min(*b);
		if ((*a)->data > max_b || (*a)->data < min_b)
		{
			if ((*b)->data == max_b)
				pa_or_pb(a, b, &count);
			else
			{
				while ((*b)->data != max_b)
				{
					ra_or_rb(b, &count);
				}
				pa_or_pb(a, b, &count);
			}
		}
		else
		{
			while(!((*a)->data > (*b)->data && (*a)->data < (*b)->prev->data))
				ra_or_rb(b, &count);
			pa_or_pb(a, b, &count);
		}
	}
	// printf("стек а до сортировки\n");
	// printf("%d\n", (*a)->data);
	// printf("%d\n", (*a)->next->data);
	// printf("%d\n", (*a)->next->next->data);
	sort_three(a, &count);
	//printf("%d это b\n", get_list_length(*b));
	while(*b)
	{
		if ((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data)
			pa_or_pb(b, a, &count);
		else if ((*b)->data < find_min(*a) || (*b)->data > find_max(*a) )
		{
			while((*a)->data != find_min(*a))
				ra_or_rb(a, &count);
			pa_or_pb(b, a, &count);
		}
		else
		{
			while(!((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data))
			{
				ra_or_rb(a, &count);
			}
			pa_or_pb(b, a, &count);
		}
	}
	while((*a)->data != find_min(*a))
		ra_or_rb(a, &count);
	//printf("%d это b\n", get_list_length(*b));
	// t_list	*current;
	// current = *a;
	// while (current->next != *a)
	// {
	// 	printf("%d\n", current->data);
	// 	current = current->next;
	// }
	printf("%d это кол-во операций\n", count);
	// printf("%d\n", current->data);
	// printf("стек а после сортировки\n");
	// printf("%d\n", (*a)->data);
	// printf("%d\n", (*a)->next->data);
	// printf("%d\n", (*a)->next->next->data);
}
