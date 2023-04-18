/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:38:36 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/04/18 13:38:37 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_maxmin(t_list *b, int *num, t_score *find)
{
	while (find->current_b->data != find_max(b))
	{	
		if (find_index(b, find_max(b)) < get_list_length(b) / 2)
			find->current_b = find->current_b->next;
		else
			find->current_b = find->current_b->prev;
		find->score++;
		if (find->score >= find->min_score && find->min_score != -1)
			break ;
	}
	if (find->min_score > find->score || find->min_score == -1)
	{
		find->min_score = find->score;
		*num = find->current_a->data;
	}
}

void	current_nearest(t_list *b, int *num, t_score *find)
{
	while (!(find->current_a->data > find->current_b->data && \
		find->current_a->data < find->current_b->prev->data))
	{	
		if (find_index(b, find_nearest(b, find->current_a->data)) \
			< get_list_length(b) / 2)
			find->current_b = find->current_b->next;
		else
			find->current_b = find->current_b->prev;
		find->score++;
		if (find->score >= find->min_score && find->min_score != -1)
			break ;
	}
	if (find->min_score > find->score || find->min_score == -1)
	{
		find->min_score = find->score;
		*num = find->current_a->data;
	}
}

void	find_min_score(t_list *a, t_list *b, int *num, t_score *find)
{
	while (get_list_length(a) - find->i > 0)
	{
		find->score = 0;
		find->current_a = a;
		find->current_b = b;
		find->j = find->i++;
		if (find->j > get_list_length(a) / 2)
			find->score = get_list_length(a) - find->j;
		else
			find->score = find->j;
		if (!(find->score >= find->min_score && find->min_score > 1))
		{
			while (find->j--)
				find->current_a = find->current_a->next;
			if (find->current_a->data > find_max(b) || \
				find->current_a->data < find_min(b))
				current_maxmin(b, num, find);
			else
				current_nearest(b, num, find);
			if (find->min_score == 0 || find->min_score == 1)
				break ;
		}
	}
}

void	rotate_push_help(t_list	**a, t_list	**b, int num)
{
	while ((*b)->data != find_max(*b) && (*a)->data != num)
	{	
		if (find_index(*a, num) < get_list_length(*a) / 2)
			rr(a, b);
		else
			rrr(a, b);
	}
}

void	rotate_push_minmax(t_list	**a, t_list	**b, int num)
{
	rotate_push_help(a, b, num);
	if ((*b)->data == find_max(*b) && (*a)->data != num)
	{	
		while ((*a)->data != num)
		{
			if (find_index(*a, num) < get_list_length(*a) / 2)
				ra_or_rb(a, "ra\n");
			else
				rra_or_rrb(a, "rra\n");
		}
	}
	else if ((*b)->data != find_max(*b) && (*a)->data == num)
	{	
		while ((*b)->data != find_max(*b))
		{
			if (find_index(*b, find_max(*b)) < get_list_length(*b) / 2)
				ra_or_rb(b, "rb\n");
			else
				rra_or_rrb(b, "rrb\n");
		}
	}
	pa_or_pb(a, b, "pb\n");
}
