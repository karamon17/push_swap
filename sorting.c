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



void	find_min_score(t_list *a, t_list *b, int *num)
{
	int min_score;
	int	score;
	int	i;
	int	j;
	t_list	*current_b;
	t_list	*current_a;
	
	i = 0;
	min_score = -1;
	while (get_list_length(a) - i > 0)
	{
		score = 0;
		current_a = a;
		current_b = b;
		j = i;
		if (j > get_list_length(a) / 2)
			score = get_list_length(a) - j;
		else
			score = j;
		if (!(score >= min_score && min_score > 1))
		{
			while (j)
			{
				current_a = current_a->next;
				j--;
			}
			if (current_a->data > find_max(b) || current_a->data < find_min(b))
			{
				while (current_b->data != find_max(b))
				{	
					if (find_index(b, find_max(b)) < get_list_length(b) / 2)
						current_b = current_b->next;
					else
						current_b = current_b->prev;
					score++;
					if (score >= min_score && min_score != -1)
						break;
				}
				if (min_score > score || min_score == -1)
				{
					min_score = score;
					*num = current_a->data;
				}
			}
			else
			{
				while (!(current_a->data > current_b->data && current_a->data < current_b->prev->data))
				{	
					if (find_index(b, find_nearest(b, current_a->data)) < get_list_length(b) / 2)
						current_b = current_b->next;
					else
						current_b = current_b->prev;
					score++;
					if (score >= min_score && min_score != -1)
						break;
				}
				if (min_score > score || min_score == -1)
				{
					min_score = score;
					*num = current_a->data;
				}
			}
			if (min_score == 0 || min_score == 1)
				break;
		}
		i++;
	}
}

void	rotate_push(t_list	**a, t_list	**b, int num)
{
	if (num > find_max(*b) || num < find_min(*b))
	{
		while ((*b)->data != find_max(*b) && (*a)->data != num)
			if (find_index(*a, num) < get_list_length(*a) / 2)
				rr(a, b);
			else
				rrr(a, b);
		if((*b)->data == find_max(*b) && (*a)->data != num)
			while((*a)->data != num)
			{	
				if (find_index(*a, num) < get_list_length(*a) / 2)
					ra_or_rb(a, "ra\n");
				else
					rra_or_rrb(a, "rra\n");
			}
		else if((*b)->data != find_max(*b) && (*a)->data == num)
			while((*b)->data != find_max(*b))
			{
				if (find_index(*b, find_max(*b)) < get_list_length(*b) / 2)
					ra_or_rb(b, "rb\n");
				else
					rra_or_rrb(b, "rrb\n");
			}
		pa_or_pb(a, b, "pb\n");
	}
	else
	{
		while (!(num > (*b)->data && num < (*b)->prev->data) && (*a)->data != num)
			if (find_index(*a, num) < get_list_length(*a) / 2)
				rr(a, b);
			else
				rrr(a, b);
		if((*a)->data == num)
		{
			while (!(num > (*b)->data && num < (*b)->prev->data))
			{	
				if (find_index(*b, find_nearest(*b, num)) < get_list_length(*b) / 2)
					ra_or_rb(b, "rb\n");
				else
					rra_or_rrb(b, "rrb\n");
			}
		}
		else if((*a)->data != num)
		{
			while ((*a)->data != num)
			{
				if (find_index(*a, num) < get_list_length(*a) / 2)
					ra_or_rb(a, "ra\n");
				else
					rra_or_rrb(a, "rra\n");
			}
		}
		pa_or_pb(a, b, "pb\n");
	}
}

void	push_allto_b(t_list	**a, t_list	**b)
{
	int	num;

	while (get_list_length(*a) > 3)
	{
		find_min_score(*a, *b, &num);
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
			while ((*a)->data != find_min(*a))
			{
				if (find_index(*a, find_min(*a)) < get_list_length(*a) / 2)
					ra_or_rb(a, "ra\n");
				else
					rra_or_rrb(a, "rra\n");
			}
		else
			while (!((*b)->data < (*a)->data && (*b)->data > (*a)->prev->data))
			{	
				if (find_index(*a, find_nearest(*a, (*b)->data)) < get_list_length(*a) / 2)
					ra_or_rb(a, "ra\n");
				else
					rra_or_rrb(a, "rra\n");
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
