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

void	rotate_push_help2(t_list **a, t_list **b, int num)
{
	if (find_index(*a, num) < get_list_length(*a) / 2 && \
		find_index(*b, find_nearest(*b, num)) < get_list_length(*b) / 2)
	{
		while (!(num > (*b)->data && num < (*b)->prev->data) \
			&& (*a)->data != num)
			rr(a, b);
	}
	else if (find_index(*a, num) > get_list_length(*a) / 2 && \
		find_index(*b, find_nearest(*b, num)) > get_list_length(*b) / 2)
	{
		while (!(num > (*b)->data && num < (*b)->prev->data) \
			&& (*a)->data != num)
			rrr(a, b);
	}
}

void	rotate_push(t_list	**a, t_list	**b, int num)
{
	rotate_push_help2(a, b, num);
	while (!(num > (*b)->data && num < (*b)->prev->data))
	{
		if (find_index(*b, find_nearest(*b, num)) < get_list_length(*b) / 2)
			ra_or_rb(b, "rb\n");
		else
			rra_or_rrb(b, "rrb\n");
	}
	while ((*a)->data != num)
	{
		if (find_index(*a, num) < get_list_length(*a) / 2)
			ra_or_rb(a, "ra\n");
		else
			rra_or_rrb(a, "rra\n");
	}
	pa_or_pb(a, b, "pb\n");
}

void	push_allto_b(t_list	**a, t_list	**b)
{
	int		num;
	t_score	find;

	while (get_list_length(*a) > 3)
	{
		find.i = 0;
		find.min_score = -1;
		find_min_score(*a, *b, &num, &find);
		if (num > find_max(*b) || num < find_min(*b))
			rotate_push_minmax(a, b, num);
		else
			rotate_push(a, b, num);
		if (check_sort_stack(a))
			return ;
	}
	if (get_list_length(*a) == 3 && !check_sort_stack(a))
		sort_three(a);
}

void	push_backto_a(t_list	**a, t_list	**b)
{
	while (*b)
	{
		if ((*b)->data < find_min(*a) || (*b)->data > find_max(*a))
		{	
			while ((*a)->data != find_min(*a))
			{
				if (find_index(*a, find_min(*a)) < get_list_length(*a) / 2)
					ra_or_rb(a, "ra\n");
				else
					rra_or_rrb(a, "rra\n");
			}
		}
		else
		{	
			while (!((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data))
			{	
				if (find_index(*a, find_nearest(*a, (*b)->data)) \
					< get_list_length(*a) / 2)
					ra_or_rb(a, "ra\n");
				else
					rra_or_rrb(a, "rra\n");
			}
		}
		pa_or_pb(b, a, "pa\n");
	}
}

void	sorting(t_list	**a, t_list	**b)
{
	push_2to_b(a, b);
	push_allto_b(a, b);
	push_backto_a(a, b);
	while ((*a)->data != find_min(*a))
	{
		if (find_index(*a, find_min(*a)) < get_list_length(*a) / 2)
			ra_or_rb(a, "ra\n");
		else
			rra_or_rrb(a, "rra\n");
	}
}
